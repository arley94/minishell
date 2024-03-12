/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:21:28 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/12 16:07:00 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**find_path(t_data *data)
{
	int		i;
	char	**paths;

	i = 0;
	if (!data->envp)
		perror("error");
	while (data->envp)
	{
		if (ft_strcmp(data->envp->name, "PATH") == 0)
			break ;
		data->envp = data->envp->next;
	}
	if (data->envp == NULL)
		return (NULL);
	paths = ft_split(data->envp->value, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*paths(t_data *data, t_cmd *cmd)
{
	char	**array_paths;
	char	*full_path;
	int		i;

	i = 0;
	if (ft_strchr(cmd->name, '/'))
		return (cmd->name);
	array_paths = find_path(data);
	while (array_paths && array_paths[i] != NULL)
	{
		full_path = ft_strjoin(array_paths[i], "/");
		full_path = ft_strjoin(full_path, cmd->name);
		if (access(full_path, F_OK) == 0)
		{
			free(array_paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_putstr_fd(cmd->name, 2);
	ft_putendl_fd(": command not found", 2);
	return (NULL);
}
