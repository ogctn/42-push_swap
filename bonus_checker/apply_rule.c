/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:34:52 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 19:33:28 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

static void	write_result(t_node **a, t_node **b, char c)
{
	if (c == 'o')
		write(1, "OK\n", 3);
	else if (c == 'k')
		write(1, "KO\n", 3);
	if (c == 'o' || c == 'k')
	{
		free_stack(*a);
		free_stack(*b);
		exit(0);
	}
}

static void	apply_rule_2(t_node **a, t_node **b, char *command)
{
	if (!ft_strcmp("rra\n", command) && command)
		rra(a);
	else if (!ft_strcmp("rrb\n", command) && command)
		rrb(b);
	else if (!ft_strcmp("rrr\n", command) && command)
		rrr(a, b);
	else if (!ft_strcmp("ra\n", command) && command)
		ra(a);
	else if (!ft_strcmp("rb\n", command) && command)
		rb(b);
	else if (!ft_strcmp("rr\n", command) && command)
		rr(a, b);
	else if (command)
		ft_error();
}

void	apply_rule(t_node **a, t_node **b, char *command)
{
	if (!command && is_sorting_needed(*a))
		write_result(a, b, 'k');
	if (!command && !is_sorting_needed(*a) && stack_len(*b) == 0)
		write_result(a, b, 'o');
	if (!command && stack_len(*b) > 0)
		write_result(a, b, 'k');
	if (!(ft_strcmp("sa\n", command)) && command)
		sa(a);
	else if (!ft_strcmp("sb\n", command) && command)
		sb(b);
	else if (!ft_strcmp("ss\n", command) && command)
		ss(a, b);
	else if (!ft_strcmp("pa\n", command) && command)
		pa(a, b);
	else if (!ft_strcmp("pb\n", command) && command)
		pb(a, b);
	else
		apply_rule_2(a, b, command);
}
