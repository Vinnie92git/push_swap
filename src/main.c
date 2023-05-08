/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:36:24 by vipalaci          #+#    #+#             */
/*   Updated: 2023/05/08 11:05:10 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_init_stack(char **args, t_stack **stack)
{
	char	**str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (args[i])
	{
		str = ft_split(args[i], ' ');
		if (ft_input_check(str) == 1)
		{
			j = 0;
			while (str[j])
			{
				if (ft_atol(str[j]) < INT_MIN || ft_atol(str[j]) > INT_MAX)
					return (0);
				ft_add_tail(stack, ft_new_node(ft_atol(str[j])));
				j++;
			}
			i++;
		}
		else
			return (0);
	}
	return (1);
}

static void	ft_push_swap(t_stack **a_stack, t_stack **b_stack, int stack_size)
{
	if (stack_size == 2 && !ft_is_sorted(*a_stack))
		ft_sa(a_stack);
	else if (stack_size == 3)
		ft_tiny_sort(a_stack);
	else if (stack_size > 3 && !ft_is_sorted(*a_stack))
		ft_sort(a_stack, b_stack);
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		stack_size;

	a_stack = NULL;
	b_stack = NULL;
	if (argc > 1)
	{
		if (!ft_init_stack(argv, &a_stack))
			ft_exit_program(1, &a_stack);
		if (ft_has_duplicate_numbers(&a_stack))
			ft_exit_program(2, &a_stack);
		stack_size = ft_stack_size(a_stack);
		ft_assign_index(a_stack, stack_size + 1);
		ft_push_swap(&a_stack, &b_stack, stack_size);
		ft_exit_program(EXIT_SUCCESS, 0);
	}
	else
		ft_exit_program(0, 0);
}
