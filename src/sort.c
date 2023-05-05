/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:21:56 by vinni             #+#    #+#             */
/*   Updated: 2023/05/05 17:49:24 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	ft_push_chunk(t_stack **a_stack, t_stack **b_stack)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_size(*a_stack);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a_stack)->index <= stack_size / 2)
		{
			ft_pb(a_stack, b_stack);
			pushed++;
		}
		else
			ft_ra(a_stack);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_pb(a_stack, b_stack);
		pushed++;
	}
}

static void	ft_shift_stack(t_stack **a_stack)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_stack_size(*a_stack);
	lowest_pos = ft_lowest_index(a_stack);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_rra(a_stack);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra(a_stack);
			lowest_pos--;
		}
	}
}

void	ft_sort(t_stack **a_stack, t_stack **b_stack)
{
	ft_push_chunk(a_stack, b_stack);
	ft_tiny_sort(a_stack);
	while (*b_stack)
	{
		ft_target_position(a_stack, b_stack);
		ft_get_cost(a_stack, b_stack);
		ft_cheapest_move(a_stack, b_stack);
	}
	if (!ft_is_sorted(*a_stack))
		ft_shift_stack(a_stack);
}
