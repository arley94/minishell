/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:22:09 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/08 11:45:11 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dup_env(t_data *data, char *name)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], name, ft_strlen(name)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	**replace_dup_env(t_data *data, char *name, char *value)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], name, ft_strlen(name)) == 0)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strjoin(name, value);
			break;
		}
		i++;
	}
	return (data->envp);
}

char	**update_envp(t_data *data, char *name, char *value)
{
	int		i;
	char	**new_envp;
	char	*add_envp;

	i = 0;
	add_envp = ft_strjoin(name, value);
	new_envp = (char **) malloc((array_len(data->envp) + 1) * sizeof(char *));
	if (!new_envp)
		return (0);
	while (data->envp[i])
	{
		new_envp[i] = data->envp[i];
		i++;
	}
	new_envp[i] = add_envp;
	new_envp[i + 1] = NULL;
	free(data->envp);
	return (new_envp);
}

void print_env(char **envp)
{
    int i;
    int j;
    char flag;
    
    i = 0;
    while (envp[i++])
    {
        j = 0;
        flag = 0;
        printf("declare -x ");
        while (envp[i][j++])
        {
            printf("%c", envp[i][j]);
            if (envp[i][j] == '=')
            {
                flag = 1;
                printf("\"");
            }
        }
        if (flag)
            printf("\"");
        printf("\n");
    }
}

void    ft_export(t_cmd *cmd, t_data *data)
{
    int i;
	char *name;
	char *value;

    i = 0;
    if (!cmd->args[0])
        print_env(data->envp);
	else
    {
		while (cmd->args[i])
		{
			name = new_env_name(cmd->args[i]);
			value = new_env_value(cmd->args[i]);
			if (check_dup_env(data, name))
				data->envp = replace_dup_env(data, name, value);
			else
				data->envp = update_envp(data, name, value);
			free(name);
			free(value);
			i++;
		}
    }
}
