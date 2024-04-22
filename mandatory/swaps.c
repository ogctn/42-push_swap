/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:22:44 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 05:34:58 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	int	len;

	len = stack_len(*head);
	if (!head || !(*head) || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_node **stack_a, int flag_ss)
{
	swap(stack_a);
	if (!flag_ss)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, int flag_ss)
{
	swap(stack_b);
	if (!flag_ss)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}
