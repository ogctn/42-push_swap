/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:45:00 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:27 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*cargo_node;

	if (!src || !dest || !(*src))
		return ;
	cargo_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	cargo_node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = cargo_node;
		cargo_node->next = NULL;
	}
	else
	{
		cargo_node->next = *dest;
		cargo_node->next->prev = cargo_node;
		*dest = cargo_node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
}
