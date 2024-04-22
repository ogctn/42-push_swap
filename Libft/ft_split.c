/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:06:44 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 12:23:24 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

ssize_t	wholelength(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

size_t	words(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = words(s, c);
	new = malloc(sizeof(char *) * wordcount + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		while (*s == c && *s != 0)
			s++;
		new[i] = malloc(sizeof(char) * wholelength(s, c) + 1);
		j = 0;
		while (*s != c && *s != 0)
			new[i][j++] = *s++;
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
