/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:22:09 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/12 11:36:35 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int valid_name(char *str)
{
    int i;

    i = 0;
    if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		printf("export: \'%s\': not a valid identifier\n", str);
		return (0);
	}
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
		{
		printf("export: \'%s\': not a valid identifier\n", str);
		return (0);
		}
        i++;
    }
    return (1);
}

int valid_value(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
		{
		printf("export: \'%s\': not a valid identifier\n", str);
		return (0);
		}
        i++;
    }
    return (1);
}

int	check_dup_env(t_llist *lst, char *name)
{
	while (lst)
	{
		if (ft_strncmp((char *)lst->name, name, ft_strlen(name)) == 0 
		&& ft_strlen(name) == ft_strlen(lst->name))
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	*replace_dup_env(t_llist *lst, char *name, char *n_value)
{
	while (lst)
	{
		if (check_dup_env(lst, name))
		{
			if (lst->value)
				free(lst->value);
			lst->value = n_value;
			return (lst->value);
		}
		lst = lst->next;;
	}
	return (NULL);
}

void	update_envp_value(t_llist *envp, char *argument)
{
	char	*name;
	char	*value;

	name = ft_substr(argument, 0, ft_charfind(argument, '='));
	if (argument[ft_strlen(argument - 1)] == '=')
		value = ft_strdup("");
	else
		value = ft_substr(argument, ft_charfind(argument, '=') + 1, ft_strlen(argument));
	if (!check_dup_env(envp, name))
		lst_add_back(&envp, lst_add_new(name, value));
	else
	{
		replace_dup_env(envp, name, value);
		free(name);
	}
}

char	*name_env(t_cmd *cmd)
{
	char	*name;
	t_list	*lst;
	
	lst = cmd->args;
	name = ft_substr(lst->content, 0, ft_charfind(lst->content, '='));
	return (name);
}

char	*value_env(t_cmd *cmd)
{
	char	*value;
	t_list	*lst;
	
	value = NULL;
	lst = cmd->args;
	if  (ft_strchr(lst->content, '='))
		value = ft_substr(lst->content, ft_charfind(lst->content, '=') + 1, ft_strlen(lst->content));
	return (value);
}

int    ft_export(t_cmd *cmd, t_data *data)
{
	t_llist	*aux_envp;
	t_list	*lst;
	
	aux_envp = data->envp;
    if (!cmd->args)
	{
        print_env(aux_envp, "declare -x %s=\"%s\"\n", "declare -x %s\n");
		return (0);
	}
	lst = cmd->args;
	while (lst)
	{
		if (!valid_name(name_env(cmd)))
		{
			printf("hola que tal %s\n", name_env(cmd));
			return (0);
		}
		if (!ft_strchr(lst->content, '='))
		{
			if (!check_dup_env(aux_envp, lst->content))
				lst_add_back(&aux_envp, lst_add_new(ft_strdup(lst->content), NULL));
		}
		else
		{
			if (valid_value(value_env(cmd)))
				update_envp_value(aux_envp, lst->content);
			else
				return (0);
		}
		lst = lst->next;
	}
	return (0);
}
