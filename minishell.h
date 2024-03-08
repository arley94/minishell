/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:09:56 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/08 11:36:16 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	"libft/libft.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>

// Data for each command
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

typedef struct s_data
{
	//Environment variables
	char	**envp;
	t_cmd	*cmd;
	
	
}			t_data;

// Init
t_cmd	*init_cmd();

// Command functions
int	is_builtin(t_cmd *cmd);

//Builtin aux
char    *new_env_name(char *str);
char	*new_env_value(char *str);
char    *home_path(t_data *data);

//Builtin functions
void	ft_echo(t_cmd *cmd);
void	ft_pwc(t_cmd *cmd);
void	ft_export(t_cmd *cmd, t_data *data);
void	ft_cd(t_data *data, t_cmd *cmd);



#endif