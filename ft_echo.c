/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:15:46 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/11 12:33:21 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_cmd *cmd)
{
	if (!cmd->args)
		printf("\n");
	else
	{
		if (ft_strcmp((char *)cmd->args->content, "-n") == 0)
			print_list(cmd->args->next, " ");
		else
		{
			print_list(cmd->args, " ");
			printf("\n");
		}	
	}
	return (0);
}

//ALTERNATIVE IN CASE STRCMP NOT POSSIBLE
/*
int	check_n(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-')
	{
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_echo(t_cmd *cmd)
{
	int	flag;
	
	if (!cmd->args)
		printf("\n");
	else
	{
		flag = check_n(cmd->args->content);
		if (flag == 1)
			print_lst(cmd->args->next, " ");
		else
		{
			print_lst(cmd->args, " ");
			printf("\n");
		}	
	}
	return (0);
}
*/
