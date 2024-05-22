/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:36:53 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/22 20:59:50 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*hold_bottom;
	t_stack	*hold_last;

	hold_bottom = *stack;
	hold_last = NULL;
	while (hold_bottom->next)
	{
		if (!hold_bottom->next->next)
		{
			hold_last = hold_bottom->next;
			hold_bottom->next = NULL;
			break ;
		}
		hold_bottom = hold_bottom->next;
	}
	hold_last->next = *stack;
	*stack = hold_last;
}

static void	rotate(t_stack **first)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *first;
	*first = (*first)->next;
	last = *first;
	while (last->next)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_x(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(str, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	ft_putstr(str);
	ft_putstr("\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		rotate_x(stack_a, stack_b, "rr");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		rotate_x(stack_a, stack_b, "rrr");
	}
}
