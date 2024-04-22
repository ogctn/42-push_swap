/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:39:11 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:26 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	space_after_sign(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (argv[i][j + 1] &&
						!(argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57))
					ft_error();
				if (!argv[i][j + 1])
					ft_error();
			}
			j++;
		}
		i++;
	}
}

char	**get_argv_str(int argc, char **argv)
{
	char	**result;
	char	*str;
	int		i;

	space_after_sign(argv);
	str = ft_strdup(argv[1]);
	if (!str)
		return (NULL);
	i = 1;
	while (++i < argc)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
	}
	result = ft_split(str, ' ');
	free(str);
	return (result);
}
