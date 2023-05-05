/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:49:04 by vinni             #+#    #+#             */
/*   Updated: 2023/05/05 17:49:09 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = ft_last_node(*stack);
	before_tail = ft_before_tail(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	ft_rra(t_stack **a_stack)
{
	ft_rev_rotate(a_stack);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **b_stack)
{
	ft_rev_rotate(b_stack);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a_stack, t_stack **b_stack)
{
	ft_rev_rotate(a_stack);
	ft_rev_rotate(b_stack);
	ft_printf("rrr\n");
}
