/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:36:07 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/17 16:38:46 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mandatory/push_swap.h"
#include <stdio.h>

void	print_stacks(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;
	
	if (!a && !b)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	printf("\n___________\n");
	if (len_a > len_b)
	{
		while (b)
		{
			printf("%d\t%d\n", a->value, b->value);
			a = a->next;
			b = b->next;
		}
		while (a)
		{
			printf("%d\t---\n", a->value);
			a = a->next;
		}
	}
	else
	{
		while (a)
		{
			printf("%d\t%d\n", a->value, b->value);
			a = a->next;
			b = b->next;
		}
		while (b)
		{
			printf("---\t%d\n", b->value);
			b = b->next;
		}
	}
	printf("___________\n");
}
