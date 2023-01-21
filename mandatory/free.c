/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:43:14 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 13:30:50 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **arr)
{
	int	i;
	int	number_str_in_array;

	i = 0;
	number_str_in_array = 0;
	while (arr[number_str_in_array] != NULL)
	{
		number_str_in_array++;
	}
	while (i < number_str_in_array)
		free(arr[i++]);
	free(arr);
}

void	free_pipex(t_pipex *pipex)
{
	free_array(pipex->cmd_paths);
	free_array(pipex->cmd1);
	free_array(pipex->cmd2);
}
