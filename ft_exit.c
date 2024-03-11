/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:31:32 by ritavasques       #+#    #+#             */
/*   Updated: 2024/03/11 20:49:30 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_cmd *cmd, t_data *data)
{
	printf("exit\n");
	data->exit_value = 0;
	if (!ft_str_isdigit(cmd->args->content))
	{
		printf("exit: %s: numeric argument required\n", cmd->args->content);
		data->exit_value = 255;
		return ;
	}
	else if (ft_lstsize(cmd->args) > 1)
	{
		printf("exit: too many arguments\n");
		data->exit_value = 1;
		return ;
	}
	else
	{
		data->exit_value = ft_atoi(cmd->args->content);
		data->exit_value = (data->exit_value % 256);
	}
	exit(data->exit_value);
	return ;
}
