/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:39:19 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/16 21:50:32 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*last_node;
	int		len;

	len = stack_len(*head);
	if (!head || !(*head) || len == 1)
		return ;
	last_node = get_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a, int flag_rr)
{
	rotate(a);
	if (!flag_rr)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int flag_rr)
{
	rotate(b);
	if (!flag_rr)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}
