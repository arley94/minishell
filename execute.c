/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:23:38 by rivasque          #+#    #+#             */
/*   Updated: 2024/03/12 16:24:21 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	child_process_1st(char **argv, char **env)
{
	char	*path;
	char	**comds;
	int		infile;
	int		use_pipe[2];
	pid_t	child;

	comds = cmds_b(argv[2]);
	path = paths_b(env, comds[0]);
	pipe(use_pipe);
	child = fork();
	if (child < 0)
		exit(EXIT_FAILURE);
	if (child == 0)
	{
		infile = open_file(argv[1], 0);
		dup2(infile, STDIN_FILENO);
		close(infile);
		unlink ("./here_doc");
		dup2(use_pipe[1], STDOUT_FILENO);
		close(use_pipe[1]);
		execve(path, comds, env);
		perror(comds[0]);
		exit(EXIT_FAILURE);
	}
	return (close(use_pipe[1]), use_pipe[0]);
}

static int	child_process_middle(int pipe_a, char **argv, char **env)
{
	char	*path;
	char	**comds;
	int		use_pipe[2];
	pid_t	child;

	comds = cmds_b(*argv);
	path = paths_b(env, comds[0]);
	pipe(use_pipe);
	child = fork();
	if (child < 0)
		exit(EXIT_FAILURE);
	if (child == 0)
	{
		dup2(pipe_a, STDIN_FILENO);
		close(pipe_a);
		dup2(use_pipe[1], STDOUT_FILENO);
		close(use_pipe[1]);
		execve(path, comds, env);
		perror(comds[0]);
		exit(EXIT_FAILURE);
	}
	close(use_pipe[1]);
	close(pipe_a);
	return (use_pipe[0]);
}

static pid_t	child_last(int argc, int pipe_a, char **argv, char **env)
{
	char	*path;
	char	**comds;
	int		outfile;
	pid_t	child_last;

	if ((ft_strncmp(argv[0], "here_doc", 8) == 0) && ft_strlen(argv[0]) == 8)
		outfile = open_file(argv[argc - 1], 2);
	else
		outfile = open_file(argv[argc - 1], 1);
	comds = cmds_b(argv[argc - 2]);
	path = paths_b(env, comds[0]);
	child_last = fork();
	if (child_last < 0)
		exit(EXIT_FAILURE);
	if (child_last == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		dup2(pipe_a, STDIN_FILENO);
		close(pipe_a);
		execve(path, comds, env);
		perror(comds[0]);
		exit(EXIT_FAILURE);
	}
	return (child_last);
}

void	pipex_b(int argc, char **argv, char **env)
{
	int		i;
	int		n_comds;
	int		pipe_a;
	pid_t	last_child;

	i = 3;
	if ((ft_strncmp(argv[1], "here_doc", 8) == 0) && ft_strlen(argv[1]) == 8)
	{
		argv++;
		argv[1] = here_doc(argv[1]);
		argc--;
	}
	n_comds = n_cmds(argc, argv);
	pipe_a = child_process_1st(argv, env);
	while (i <= n_comds)
	{
		pipe_a = child_process_middle(pipe_a, &argv[i], env);
		i++;
	}
	last_child = child_last(argc, pipe_a, argv, env);
	ft_wait(last_child);
}
