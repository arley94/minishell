/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:22:09 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/11 15:36:09 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int valid_name(char *str)
{
    int i;

    i = 0;
    if (!ft_isalpha(str[0]) || str[0] != '_')
	{
		printf("export: \'%s\': not a valid identifier", str);
		return (0);
	}
    while (str[i])
    {
        if (!ft_isalnum(str[i]) || str[i] != '_')
		{
		printf("export: \'%s\': not a valid identifier", str);
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
		if (!valid_name(lst->content))
			return (1);
		if (!ft_strchr(lst->content, '='))
		{
			if (!check_dup_env(aux_envp, lst->content))
				lst_add_back(&aux_envp, lst_add_new(ft_strdup(lst->content), NULL));
		}
		else
			update_envp_value(aux_envp, lst->content);
		lst = lst->next;
	}
	return (0);
}
