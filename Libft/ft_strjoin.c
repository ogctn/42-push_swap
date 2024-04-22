/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:42:49 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 12:55:21 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	a;
	size_t	c;
	char	*s;

	i = ((ft_strlen(s1)) + (ft_strlen(s2)) + 1);
	s = (char *)malloc(sizeof(char) * i);
	a = 0;
	c = 0;
	while ((char)s1[a] != '\0')
	{
		s[c] = s1[a];
		c++;
		a++;
	}
	a = 0;
	while ((char)s2[a] != '\0')
	{
		s[c] = s2[a];
		c++;
		a++;
	}
	s[c] = '\0';
	free(s1);
	return (s);
}
