/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:04:04 by caliman           #+#    #+#             */
/*   Updated: 2024/05/21 00:48:00 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '+')
	{
		if (*s2 != '+')
			s1++;
	}
	else
	{
		if (*s2 == '+')
			s2++;
	}
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void    error_exit(t_stack_node **a, t_stack_node **b)
{
    if (!a || *a)
        free_stack(a);
    if (!b || *b)
        free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}
