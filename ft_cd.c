/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:42:27 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/11 14:11:15 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_home(t_cmd *cmd)
{
	(void)cmd;
	char	*path;
	
	path = getenv("HOME");
	printf("Home: %s\n", path);
	if (chdir(path) < 0)
	{
		printf("HOME not set");
		return (NULL);
	}
	return (path);
}

char	*find_path_old(t_cmd *cmd)
{
	(void)cmd;
	char *path;
	
	path = getenv("OLDPWD");
	printf("Old: %s\n", path);
	if (chdir(path) < 0)
	{
		printf("OLDPWD not set");
		return (NULL);
	}
	return (path);
}

char	*find_path_args(t_cmd *cmd)
{
	char *path;

	path = cmd->args->content;
	if (chdir(path) < 0)
	{
		printf("cd: %s: No such file or directory\n", path);
		return (NULL);
	}
	return (path);
}

int	ft_cd(t_cmd *cmd)
{
	
	if (!cmd->args || ft_strcmp(cmd->args->content, "~") == 0)
		return (chdir(path_home(cmd)));
	else if (ft_strcmp(cmd->args->content, "-") == 0)
		return (chdir(find_path_old(cmd)));
	else
		return (chdir(find_path_args(cmd)));
	return (0);
}
