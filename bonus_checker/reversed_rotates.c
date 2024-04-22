/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:49:52 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:27 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate(t_node **head)
{
	t_node	*last_node;
	int		len;

	len = stack_len(*head);
	if (!head || !(*head) || len == 1)
		return ;
	last_node = get_last_node(*head);
	last_node->prev->next = NULL;
	last_node->next = *head;
	last_node->prev = NULL;
	(*head) = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **a)
{
	rev_rotate(a);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}
