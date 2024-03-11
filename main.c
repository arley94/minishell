/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:22:32 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/11 14:14:16 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	t_cmd	*cmd;
	t_data	*data;
	
	cmd = init_cmd();
	data = init_data();
	cmd->name = argv[1];
	cmd->args = get_args(argv);
	data->envp = get_envp(envp);
	printf("%s\n", cmd->name);
	exec_builtin(cmd, envp);
	return (0);
}



