/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:51:22 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:28 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}
