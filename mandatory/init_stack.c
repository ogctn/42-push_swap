/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:34:20 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 14:45:10 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp_next;

	if (!stack)
		return ;
	while (stack)
	{
		tmp_next = stack->next;
		free(stack);
		stack = tmp_next;
	}
}

void	free_matrix(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

void	init_stack(t_node **a, int argc, char **argv)
{
	char	**argv_str;
	long	nbr;
	int		i;

	argv_str = get_argv_str(argc, argv);
	i = 0;
	while (argv_str[i])
	{
		nbr = ft_atoi2(argv_str[i]);
		append_node(a, (int)nbr);
		i++;
	}
	free_matrix(argv_str);
}
