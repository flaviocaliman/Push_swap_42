/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:04:04 by caliman           #+#    #+#             */
/*   Updated: 2024/05/22 20:19:56 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	if (*str1 == '+')
	{
		if (*str2 != '+')
			str1++;
	}
	else
	{
		if (*str2 == '+')
			str2++;
	}
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error_exit(t_stack **a, t_stack **b)
{
	if (!a || *a)
		free_stack(a);
	if (!b || *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
