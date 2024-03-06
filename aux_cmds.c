/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:58:05 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/06 11:41:23 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"

char	**cmds(char *argv)
{
	char	**array_cmds;

	array_cmds = ft_split(argv, ' ');
	return (array_cmds);
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


int	is_token(t_cmd **argv)
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i] == '<' || argv[i] == '>'|| 
		argv[i] == '<<' || argv[i] == '>>' || argv[i] == '|')
			return (1);
		else 
			return (0);
		i++;
	}
}*/

