/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:42:29 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 14:10:25 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *name, char *str_error)
{
	ft_putstr_fd("./pipex: ", 2);
	ft_putstr_fd(str_error, 2);
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(name, 2);
	}
	ft_putstr_fd("\n", 2);
}

void	error_dup(t_pipex *pipex)
{
	free_pipex(pipex);
	perror("./pipex");
	exit(ERR_DUP);
}

void	error_open_file(t_pipex *pipex, int fd)
{
	free_pipex(pipex);
	close_file(fd, NULL);
	exit (ERR_FILE);
}

void	error_fork(t_pipex *pipex, char **argv)
{
	close_file(pipex->infile, argv[1]);
	close_file(pipex->outfile, argv[4]);
	close_file(pipex->tube[0], NULL);
	close_file(pipex->tube[1], NULL);
	free_pipex(pipex);
	perror ("./pipex: ");
	exit (ERR_FORK);
}
