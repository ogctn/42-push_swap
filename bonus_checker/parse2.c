/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:39:16 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:26 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_size(int argc, char **argv)
{
	char	**str;
	int		i;
	int		size;

	str = get_argv_str(argc, argv);
	size = 0;
	i = 0;
	while (str[i++])
		size++;
	free_matrix(str);
	return (size);
}

int	*get_arg_array(int argc, char **argv)
{
	int		*arr;
	char	**str;
	int		i;
	int		size;

	str = get_argv_str(argc, argv);
	size = get_size(argc, argv);
	arr = malloc(sizeof(int) * (size));
	i = 0;
	while (str[i])
	{
		arr[i] = ft_atoi2(str[i]);
		i++;
	}
	free_matrix(str);
	return (arr);
}

void	is_any_empty(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = -1;
		while (argv[i][++j] == ' ')
			;
		if (!argv[i][j])
			ft_error();
		i++;
	}
}

void	duplication_check(int argc, char **argv)
{
	int	*argv_arr;
	int	i;
	int	j;
	int	size;

	argv_arr = get_arg_array(argc, argv);
	size = get_size(argc, argv);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (argv_arr[i] == argv_arr[j])
				ft_error();
			j++;
		}
		i++;
	}
	free(argv_arr);
}

void	check_inputs(int argc, char **argv)
{
	if (1 == argc)
		exit(0);
	is_any_empty(argv);
	duplication_check(argc, argv);
}
