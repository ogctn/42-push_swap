/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:08:21 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 19:33:04 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*command;

	check_inputs(argc, argv);
	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		init_stack(&a, argc, argv);
		while (1)
		{
			command = get_next_line(0);
			apply_rule(&a, &b, command);
			free(command);
		}
	}
	else
		return (0);
}
