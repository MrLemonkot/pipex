/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:41:31 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 13:44:30 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child_0(t_pipex	*pipex, char **argv, char **envp)
{
	close_file(pipex->outfile, argv[4]);
	close_file(pipex->tube[0], NULL);
	if (pipex->infile == -1)
		error_open_file(pipex, pipex->tube[1]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
	{
		close_file(pipex->infile, argv[1]);
		close_file(pipex->tube[1], NULL);
		error_dup(pipex);
	}
	if (dup2(pipex->tube[1], STDOUT_FILENO) == -1)
	{
		close_file(pipex->infile, argv[1]);
		close_file(pipex->tube[1], NULL);
		error_dup(pipex);
	}
	close_file(pipex->infile, argv[1]);
	close_file(pipex->tube[1], NULL);
	exec_without_path(pipex, envp, pipex->cmd1);
	exec_with_path(pipex, envp, pipex->cmd1);
	ft_error(pipex->cmd1[0], "Command not found");
	free_pipex(pipex);
	exit(ERR_EXECUTE_CMD);
}

static void	ft_child_1(t_pipex	*pipex, char **argv, char **envp)
{
	close_file(pipex->infile, argv[1]);
	close_file(pipex->tube[1], NULL);
	if (pipex->outfile == -1)
		error_open_file(pipex, pipex->tube[0]);
	if (dup2(pipex->tube[0], STDIN_FILENO) == -1)
	{
		close_file(pipex->outfile, argv[4]);
		close_file(pipex->tube[0], NULL);
		error_dup(pipex);
	}
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
	{
		close_file(pipex->outfile, argv[4]);
		close_file(pipex->tube[0], NULL);
		error_dup(pipex);
	}
	close_file(pipex->outfile, argv[4]);
	close_file(pipex->tube[0], NULL);
	exec_without_path(pipex, envp, pipex->cmd2);
	exec_with_path(pipex, envp, pipex->cmd2);
	ft_error(pipex->cmd2[0], "Command not found");
	free_pipex(pipex);
	exit(ERR_EXECUTE_CMD);
}

void	ft_child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_fork(pipex, argv);
	else if (pipex->pid1 == 0)
		ft_child_0(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_fork(pipex, argv);
	else if (pipex->pid2 == 0)
		ft_child_1(pipex, argv, envp);
}
