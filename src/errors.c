/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:51:43 by vipalaci          #+#    #+#             */
/*   Updated: 2023/05/08 13:37:44 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	ft_input_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
			{
				if (str[i][j + 1] < '0' || str[i][j + 1] > '9')
					return (0);
				j++;
			}
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_has_duplicate_numbers(t_stack **stack)
{
	t_stack	*current_node;
	t_stack	*comparison_node;
	size_t	count;

	current_node = *stack;
	while (current_node != NULL)
	{
		count = 0;
		comparison_node = *stack;
		while (comparison_node != NULL)
		{
			if (current_node->number == comparison_node->number)
				count++;
			comparison_node = comparison_node->next;
		}
		if (count > 1)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

void	ft_exit_program(int error_code, t_stack **stack)
{
	if (stack)
		ft_free_stack(stack);
	if (error_code != EXIT_SUCCESS)
		write(2, "Error\n", 6);
	exit(error_code);
}

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return ;
}
