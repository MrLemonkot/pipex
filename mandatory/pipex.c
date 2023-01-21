/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:44:16 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 14:22:02 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_file(int fd, char *name)
{
	if (fd != -1)
	{
		if (close(fd) == -1)
			ft_error(name, strerror(errno));
	}
}

void	open_files(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		ft_error(argv[1], strerror(errno));
	pipex->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		ft_error(argv[4], strerror(errno));
}

static void	ft_waitpid(t_pipex *pipex, int *status_0, int *status_1)
{
	if (pipex->pid1 > 0)
	{
		if (waitpid(pipex->pid1, status_0, 0) == -1)
			ft_error(NULL, strerror(errno));
	}
	if (pipex->pid2 > 0)
	{
		if (waitpid(pipex->pid2, status_1, 0) == -1)
			ft_error(NULL, strerror(errno));
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		exc[2];

	if (argc != 5)
	{
		ft_putstr_fd("./pipex: Invalid number of arguments\n", 2);
		exit (ERR_NUMBER_ARG);
	}
	if (pipe(pipex.tube) < 0)
	{
		perror("./pipex: ");
		exit(ERR_PIPE);
	}
	open_files(&pipex, argv);
	ft_parssplit(&pipex, argv, envp);
	ft_child(&pipex, argv, envp);
	free_pipex(&pipex);
	close_file(pipex.infile, argv[1]);
	close_file(pipex.outfile, argv[4]);
	close_file(pipex.tube[0], NULL);
	close_file(pipex.tube[1], NULL);
	ft_waitpid(&pipex, &exc[0], &exc[1]);
	if (WIFEXITED(exc[1]) != 0)
		return (WEXITSTATUS(exc[1]));
	return (0);
}
