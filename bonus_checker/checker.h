/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:34:41 by ogcetin           #+#    #+#             */
/*   Updated: 2023/09/18 17:30:38 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../gnl/get_next_line.h"
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

int		stack_len(t_node *stack);
t_node	*get_last_node(t_node *head);
void	append_node(t_node **stack, int nbr);
void	init_stack(t_node **a, int argc, char **argv);
int		is_sorting_needed(t_node *stack);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	apply_rule(t_node **a, t_node **b, char *command);

#endif
