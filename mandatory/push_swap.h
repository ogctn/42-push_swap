/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:13:10 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 16:37:44 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	int				above_median;
	int				is_cheapest;
	int				size;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

int		is_space(char c);
int		ft_atoi2(char *str);
char	**get_argv_str(int argc, char **argv);
int		*get_arg_array(int argc, char **argv);
int		get_size(int argc, char **argv);
void	check_inputs(int argc, char **argv);

void	free_matrix(char **mat);
void	free_stack(t_node *stack);
void	ft_error(void);

void	append_node(t_node **stack, int nbr);
void	init_stack(t_node **a, int argc, char **argv);
void	init_nodes(t_node *a, t_node *b);
int		stack_len(t_node *stack);
void	set_current_position(t_node *stack);
void	set_cheapest(t_node *b);

t_node	*get_last_node(t_node *head);
t_node	*get_smallest(t_node *stack);
t_node	*get_cheapest(t_node *stack);
int		is_sorting_needed(t_node *stack);

void	sa(t_node **stack_a, int flag_ss);
void	sb(t_node **stack_b, int flag_ss);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **a, int flag_rr);
void	rb(t_node **b, int flag_rr);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a, int flag_rr);
void	rrb(t_node **b, int flag_rr);
void	rrr(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	rotate_node_to_top(t_node **stack, t_node *node, char which_stack);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);

#endif
