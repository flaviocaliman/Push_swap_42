/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:09:55 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/22 21:09:57 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	push(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;

	if (!top_a)
		return ;
	tmp = (*top_a)->next;
	(*top_a)->next = *top_b;
	*top_b = *top_a;
	*top_a = tmp;
}

void	swap_x(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(*stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		swap(*stack_b);
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	if (ft_strcmp(str, "pa") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "pb") == 0)
		push(stack_a, stack_b);
	ft_putstr(str);
	ft_putstr("\n");
}
