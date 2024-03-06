/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:22:32 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/06 14:24:04 by rivasque         ###   ########.fr       */
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
