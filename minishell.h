/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:09:56 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/05 15:56:02 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	"libft/libft.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef struct	s_cmd
{
	char			*path;
	char			**argv;
	int				is_builtin;
	struct	s_cmd	*next;
	
}					t_cmd;

int	is_token(t_cmd **argv);
int	is_builtin(t_cmd **argv);

#endif