/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:17:41 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/06 14:28:13 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwc(t_cmd *cmd)
{
	(void)cmd;
	char *str;

	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
}
