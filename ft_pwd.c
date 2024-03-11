/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:17:41 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/11 13:04:33 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	(void)cmd;
	char *str;

	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
	return (0);
}
