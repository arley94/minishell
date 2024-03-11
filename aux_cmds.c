/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:58:05 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/11 13:56:41 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_args(char **argv)
{
	int		i;
    t_list	*args;
	
	i = 2;
	args = NULL;
	while (argv[i])
	{
		ft_lstadd_back(&args, ft_lstnew(argv[i]));
		i++;
	}
	return (args);
}

int	is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->name, "echo") == 0 || ft_strcmp(cmd->name, "cd") == 0 ||
		ft_strcmp(cmd->name, "pwc") == 0 || ft_strcmp(cmd->name, "export") == 0 ||
		ft_strcmp(cmd->name, "unset") == 0 || ft_strcmp(cmd->name, "env") == 0 ||
		ft_strcmp(cmd->name, "exit") == 0)
			return (1);
	return (0);
}

