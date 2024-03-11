/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:09:56 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/11 20:51:23 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	"libft/libft.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>

//linked list structre 
typedef struct		s_llist
{
	struct s_llist	*next;
	struct s_llist	*prev;
	void			*name;
	void			*value;
}					t_llist;

// Data for each command
typedef struct	s_cmd
{
	//command name
	char			*name;
	char			*path;
	//Comand arguments(not taking into account the command itself)
	t_list			*args;
	//Number of arguments
	int				size;
	int				is_builtin;
	
}					t_cmd;

typedef struct s_data
{
	//Environment variables
	t_llist	*envp;

	//return value (last command)
	int		exit_value;
	
	
}			t_data;

// Init
t_cmd	*init_cmd();
t_data	*init_data();

// Command functions
int		is_builtin(t_cmd *cmd);
t_list	*get_args(char **argv);

//Builtin aux
t_llist	*get_envp(char **envp);
void	print_env(t_llist *llst, char *str1, char *str2);
int		valid_name(char *str);

//Builtin functions
int		ft_echo(t_cmd *cmd);
int		ft_pwd(t_cmd *cmd);
int		ft_export(t_cmd *cmd, t_data *data);
int		ft_cd(t_cmd *cmd);
int		ft_env(char **envp);
void	ft_exit(t_cmd *cmd, t_data *data);

//General aux functions
void	lst_add_back(t_llist **llst, t_llist *new);
t_llist	*lst_add_new(void *name, void *value);
t_llist	*llist_cpy(t_llist *llst);
void	llist_remove(t_llist **lst);

//execute
void    exec_builtin(t_cmd *cmd, char **envp);


#endif