/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:24:59 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/12 16:25:28 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait(pid_t child_last)
{
	int	last_exc;
	int	status;
	int	exit_code;

	last_exc = 0;
	while (last_exc != -1)
	{
		last_exc = waitpid(-1, &status, 0);
		if (last_exc == child_last)
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
	}
	exit(exit_code);
}
