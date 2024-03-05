/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:15:46 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/05 15:41:28 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "echo") == 0)
		{
			i++;
			if (ft_strcmp(argv[i], "-n") == 0)
			{
				i++;
				while (!is_token(argv[i]))
				{
					printf("%s", argv[i]);
					printf(" ");
					i++;
				}
			}
			else
			{
				while (!is_token(argv[i]))
				{
					printf("%s", argv[i]);
					printf(" ");
					i++;
				}
			}
		}
		i++;
	}
}