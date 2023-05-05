/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinni <vinni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:36:56 by vipalaci          #+#    #+#             */
/*   Updated: 2023/05/05 17:49:36 by vinni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

t_stack	*ft_last_node(t_stack *stack)
{
	t_stack	*current_node;

	current_node = stack;
	while (current_node)
	{
		if (current_node->next == NULL)
			break ;
		current_node = current_node->next;
	}
	return (current_node);
}

t_stack	*ft_before_tail(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_add_head(t_stack **stack, t_stack *node)
{
	t_stack	*current_node;

	if (!stack || !node)
		return ;
	current_node = *stack;
	*stack = node;
	node->next = current_node;
}

void	ft_add_tail(t_stack **stack, t_stack *node)
{
	t_stack	*current_node;

	if (!stack || !node)
		return ;
	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	current_node = ft_last_node(*stack);
	current_node->next = node;
}

t_stack	*ft_new_node(int number)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->index = 0;
	new_node->pos = -1;
	new_node->target_pos = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = NULL;
	return (new_node);
}
