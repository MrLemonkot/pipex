/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:43:19 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 14:17:43 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**find_path(char **envp)
{
	int		i;
	char	**cmd_path;
	size_t	len;

	len = ft_strlen(PATH);
	if (!envp)
		return (NULL);
	if (!(*envp))
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		if (!ft_strncmp(envp[i], PATH, len))
			break ;
		i++;
	}
	cmd_path = ft_split(envp[i] + len, ':');
	if (!cmd_path)
	{
		perror("./pipex: ");
		exit (ERR_MEMORY_ALLOCATE);
	}
	return (cmd_path);
}

static char	**get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}

void	ft_parssplit(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd_paths = find_path(envp);
	pipex->cmd1 = get_cmd(argv[2]);
	pipex->cmd2 = get_cmd(argv[3]);
	if (!pipex->cmd1 || !pipex->cmd2)
	{
		free_array(pipex->cmd_paths);
		perror("./pipex");
		exit (ERR_MEMORY_ALLOCATE);
	}
}
