/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:06:11 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/17 15:24:10 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_node *stack)
{
	int	i;
	int	median;

	if (stack == NULL)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_node *a, t_node *b)
{
	t_node	*iter_a;
	t_node	*target_node;
	long	min_bigger;

	while (b)
	{
		min_bigger = LONG_MAX;
		iter_a = a;
		while (iter_a)
		{
			if (iter_a->value > b->value && iter_a->value < min_bigger)
			{
				min_bigger = iter_a->value;
				target_node = iter_a;
			}
			iter_a = iter_a->next;
		}
		if (min_bigger == LONG_MAX)
			b->target_node = get_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	set_push_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - b->current_position;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_node *b)
{
	long	min_price;
	t_node	*cheapest_node;

	if (b == NULL)
		return ;
	min_price = LONG_MAX;
	while (b)
	{
		if (b->push_price < min_price)
		{
			min_price = b->push_price;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->is_cheapest = 1;
}

void	init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_push_price(a, b);
	set_cheapest(b);
}
