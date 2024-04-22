/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:00:04 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/17 16:34:45 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorting_needed(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->next->value < stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static t_node	*get_highest(t_node *stack)
{
	t_node	*highest_node;

	if (!stack)
		return (NULL);
	highest_node = stack;
	while (stack)
	{
		if (stack->value > highest_node->value)
			highest_node = stack;
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_node **a)
{
	t_node	*highest_node;

	highest_node = get_highest(*a);
	if (*a == highest_node)
		ra(a, 0);
	else if ((*a)->next == highest_node)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		rotate_node_to_top(a, get_smallest(*a), 'a');
		pb(a, b);
	}
}
