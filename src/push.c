/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:49:23 by vinni             #+#    #+#             */
/*   Updated: 2023/05/05 17:48:53 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	ft_pa(t_stack **a_stack, t_stack **b_stack)
{
	ft_push(b_stack, a_stack);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **a_stack, t_stack **b_stack)
{
	ft_push(a_stack, b_stack);
	ft_printf("pb\n");
}
