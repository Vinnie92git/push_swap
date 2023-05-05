/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:30:54 by vinni             #+#    #+#             */
/*   Updated: 2023/05/05 17:49:17 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = ft_last_node(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ft_ra(t_stack **a_stack)
{
	ft_rotate(a_stack);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **b_stack)
{
	ft_rotate(b_stack);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a_stack, t_stack **b_stack)
{
	ft_rotate(a_stack);
	ft_rotate(b_stack);
	ft_printf("rr\n");
}
