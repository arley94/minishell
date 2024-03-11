/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:30:04 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/11 13:43:27 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd()
{
	return ((t_cmd *) malloc(sizeof(t_cmd)));
}

t_data	*init_data()
{
	return ((t_data *) malloc(sizeof(t_data)));	
}
