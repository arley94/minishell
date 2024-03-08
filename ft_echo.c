/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:15:46 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/08 11:37:18 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int	i;
	int	len;

	i = 0;
	len = array_len(cmd->args) - 1;
	if (!cmd->args[0])
		printf("\n");
	if (ft_strcmp(cmd->args[i], "-n") == 0)
	{
		i = 1;
		while (i < len)
		{
			printf("%s", cmd->args[i]);
			printf(" ");
			i++;
		}
		printf("%s", cmd->args[len]);
	}	
	else
	{
		i = 0;
		while (i < len)
		{
			printf("%s", cmd->args[i]);
			printf(" ");
			i++;
		}
		printf("%s", cmd->args[len]);
		printf("\n");
	}
}
