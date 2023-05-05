/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:36:16 by vinni             #+#    #+#             */
/*   Updated: 2023/05/05 17:48:38 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	ft_rev_rotate_both(t_stack **a_stack, t_stack **b_stack,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(a_stack, b_stack);
	}
}

static void	ft_rotate_both(t_stack **a_stack, t_stack **b_stack, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(a_stack, b_stack);
	}
}

static void	ft_rotate_a(t_stack **a_stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra(a_stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rra(a_stack);
			(*cost)++;
		}
	}
}

static void	ft_rotate_b(t_stack **b_stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb(b_stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrb(b_stack);
			(*cost)++;
		}
	}
}

void	ft_move(t_stack **a_stack, t_stack **b_stack, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rev_rotate_both(a_stack, b_stack, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(a_stack, b_stack, &cost_a, &cost_b);
	ft_rotate_a(a_stack, &cost_a);
	ft_rotate_b(b_stack, &cost_b);
	ft_pa(a_stack, b_stack);
}
