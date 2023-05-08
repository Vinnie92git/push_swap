/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:38:24 by vipalaci          #+#    #+#             */
/*   Updated: 2023/05/08 13:47:46 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void	ft_get_cost(t_stack **a_stack, t_stack **b_stack);
void	ft_cheapest_move(t_stack **a_stack, t_stack **b_stack);
void	ft_exit_program(int error_code, t_stack **stack);
void	ft_move(t_stack **a_stack, t_stack **b_stack, int cost_a, int cost_b);
void	ft_target_position(t_stack **a_stack, t_stack **b_stack);
void	ft_pa(t_stack **a_stack, t_stack **b_stack);
void	ft_pb(t_stack **a_stack, t_stack **b_stack);
void	ft_rra(t_stack **a_stack);
void	ft_rrb(t_stack **b_stack);
void	ft_rrr(t_stack **a_stack, t_stack **b_stack);
void	ft_ra(t_stack **a_stack);
void	ft_rb(t_stack **b_stack);
void	ft_rr(t_stack **a_stack, t_stack **b_stack);
void	ft_sa(t_stack **a_stack);
void	ft_sb(t_stack **b_stack);
void	ft_ss(t_stack **a_stack, t_stack **b_stack);
void	ft_tiny_sort(t_stack **stack);
void	ft_sort(t_stack **a_stack, t_stack **b_stack);
void	ft_free_stack(t_stack **stack);
void	ft_add_head(t_stack **stack, t_stack *node);
void	ft_add_tail(t_stack **stack, t_stack *node);
void	ft_assign_index(t_stack *a_stack, int stack_size);
void	ft_free_array(char **str);

int		ft_generate_stack(char **str, t_stack **stack);
int		ft_input_check(char **str);
int		ft_has_duplicate_numbers(t_stack **stack);
int		ft_init_stack(char **args, t_stack **stack);
int		ft_is_sorted(t_stack *stack);
int		ft_lowest_index(t_stack **stack);
int		ft_stack_size(t_stack	*stack);
int		ft_nb_abs(int nb);

long	ft_atol(char *str);

t_stack	*ft_last_node(t_stack *stack);
t_stack	*ft_before_tail(t_stack *stack);
t_stack	*ft_new_node(int number);

#endif
