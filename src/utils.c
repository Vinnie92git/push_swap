/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:25:47 by vipalaci          #+#    #+#             */
/*   Updated: 2023/05/08 11:26:10 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

long	ft_atol(char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	number *= sign;
	return (number);
}

int	ft_nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_assign_index(t_stack *a_stack, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = a_stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->number == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->number > value && ptr->index == 0)
			{
				value = ptr->number;
				highest = ptr;
				ptr = a_stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
