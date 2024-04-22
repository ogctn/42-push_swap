/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:52:23 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/16 21:50:45 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rra(t_node **a, int flag_rrr)
{
	rev_rotate(a);
	if (!flag_rrr)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int flag_rrr)
{
	rev_rotate(b);
	if (!flag_rrr)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}
