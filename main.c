/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:22:32 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/08 11:49:52 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_cmd 	*cmd;
	
	cmd = init_cmd();
	cmd->args = argv;
	ft_echo(cmd);
	ft_pwc(cmd);
}
