/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:58:08 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:37 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static void	atoi_error(long long result, char c)
{
	if (c == '+' || c == '-')
		ft_error();
	if (!(result <= 2147483647 && result >= -2147483648))
		ft_error();
}

int	ft_atoi2(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i++] - 48);
		else
			ft_error();
	}
	result = result * sign;
	atoi_error(result, str[i]);
	return (result);
}
