/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:44:48 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 13:45:12 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

# define ERR_FILE 3
# define ERR_READ_CMD 4
# define ERR_PIPE 9
# define ERR_EXECUTE_CMD 127
# define ERR_NUMBER_ARG 1
# define ERR_FORK 6
# define ERR_MEMORY_ALLOCATE 2
# define ERR_DUP 7
# define ERR_EXEC 8
# define PATH "PATH="

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	**cmd_paths;
	char	**cmd1;
	char	**cmd2;
}t_pipex;

void		close_file(int fd, char *name);
int			main(int argc, char *argv[], char *envp[]);
void		exec_without_path(t_pipex *pipex, char **envp, char **cmd);
void		exec_with_path(t_pipex *pipex, char **envp, char **cmd);
void		ft_error(char *name, char *str_error);
void		error_dup(t_pipex *pipex);
void		error_open_file(t_pipex *pipex, int fd);
void		error_fork(t_pipex *pipex, char **argv);
void		ft_parssplit(t_pipex *pipex, char **argv, char **envp);
void		ft_child(t_pipex *pipex, char **argv, char **envp);
void		free_array(char **arr);
void		free_pipex(t_pipex *pipex);
char		**ft_split(char const *s, char c);
char		*ft_strdup(char *src);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t len);
void		ft_putstr_fd(char *s, int fd);

#endif
