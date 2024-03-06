/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:09:56 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/06 16:02:44 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	"libft/libft.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>

typedef struct	s_cmd
{
	//command name
	char			*name;
	char			*path;
	//Comand arguments(not taking into account the command itself)
	char			**args;
	//Number of arguments
	int				size;
	int				is_builtin;
	struct	s_cmd	*next;
	
}					t_cmd;

// General functions
int	array_size(char **argv);

// Init
t_cmd	*init_cmd();

// Command functions
int	is_builtin(t_cmd *cmd);

//Builtin functions
void	ft_echo(t_cmd *cmd);
void	ft_pwc(t_cmd *cmd);

#endif