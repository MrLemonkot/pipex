/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:47:28 by akayle            #+#    #+#             */
/*   Updated: 2022/04/03 13:14:42 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	**ft_freemalloc(char **massiv)
{
	size_t	i;

	i = 0;
	while (massiv[i])
	{
		free(massiv[i]);
		i++;
	}
	free(massiv);
	return (0);
}

int	count_words(char const *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

char	*str_mass(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	strings;
	char	**str;

	i = 0;
	if (s == NULL)
		return (NULL);
	strings = count_words(s, c);
	str = malloc(sizeof(char *) * (strings + 1));
	if (str == NULL)
		return (NULL);
	while (i < strings)
	{
		while (*s && *s == c)
			s++;
		str[i] = str_mass(s, c);
		if (str[i] == NULL)
			ft_freemalloc(str);
		while (*s && *s != c)
			s++;
		i++;
	}
	str[i] = NULL;
	return (str);
}
