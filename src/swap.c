/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:18:35 by vinni             #+#    #+#             */
/*   Updated: 2023/05/05 17:49:43 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	ft_sa(t_stack **a_stack)
{
	ft_swap(*a_stack);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b_stack)
{
	ft_swap(*b_stack);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a_stack, t_stack **b_stack)
{
	ft_swap(*a_stack);
	ft_swap(*b_stack);
	ft_printf("ss\n");
}
