/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:42:27 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/08 13:33:44 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_home(t_data *data)
{
	char	*path;
	
	path = ft_strdup(getenv("HOME"));
	if (chdir(path) < 0)
	{
		printf("HOME not set");
		free(path);
		return (NULL);
	}
	return (path);
}

char	*find_path_old(t_data *data)
{
	char *path;

	path = ft_strdup(getenv("OLDPWD"));
	if (chdir(path) < 0)
	{
		printf("OLDPWD not set");
		free(path);
		return (NULL);
	}
	return (path);
}

char	*find_path_args(t_data *data, t_cmd *cmd)
{
	char *path;

	path = ft_strdup(cmd->args[0]);
	if (chdir(path) < 0)
	{
		printf("No such file or directory");
		free(path);
		return (NULL);
	}
	return (path);
}

void	cd_management(t_data *data, t_cmd *cmd)
{
	char	*path;

	if (!cmd->args[0] || cmd->args[0][0] == '~')
		find_path_home(data);
	else if (cmd->args[0] == "-")
		find_path_home(data);
	else
		find_path_args(data, cmd);
	chdir(path);
}

