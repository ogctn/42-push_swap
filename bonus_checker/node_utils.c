/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:55:56 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:59:07 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	stack_len(t_node *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_node	*get_last_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

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

void	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->is_cheapest = 0;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
