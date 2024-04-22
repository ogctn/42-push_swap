/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:47:23 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 16:27:33 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	check_inputs(argc, argv);
	a = NULL;
	b = NULL;
	init_stack(&a, argc, argv);
	if (is_sorting_needed(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
