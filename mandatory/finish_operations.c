/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:04:16 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/17 16:30:41 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_node_to_top(t_node **stack, t_node *node, char which_stack)
{
	while (*stack != node)
	{
		if (which_stack == 'a')
		{
			if (node->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (which_stack == 'b')
		{
			if (node->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

static void	rotate_both_top(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	rev_rotate_both_top(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	rotate_push_node(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both_top(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both_top(a, b, cheapest_node);
	rotate_node_to_top(b, cheapest_node, 'b');
	rotate_node_to_top(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		size_a;

	size_a = stack_len(*a);
	if (size_a == 5)
		sort_five(a, b);
	else
		while (size_a-- > 3)
			pb(a, b);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		rotate_push_node(a, b);
	}
	set_current_position(*a);
	smallest = get_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, 0);
	else
		while (*a != smallest)
			rra(a, 0);
}
