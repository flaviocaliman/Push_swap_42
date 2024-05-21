/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:36:53 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/18 11:23:55 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **first)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = *first;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *first;
	*first = last;
}

static void	rotate(t_stack_node **first)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	tmp = *first;
	*first = (*first)->next;
	last = *first;
	while (last->next)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_x(t_stack_node **stack_a, t_stack_node **stack_b, char *str)
{
	if (ft_strcmp(str, "ra") == 0)//utils01.c
		rotate(stack_a);
	else if (ft_strcmp(str, "rb") == 0)//utils01.c
		rotate(stack_b);
	else if (ft_strcmp(str, "rr") == 0)//utils01.c
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(str, "rra") == 0)//utils01.c
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)//utils01.c
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)//utils01.c
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	ft_putstr(str);//utils01.c
	ft_putstr("\n");//utils01.c
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		rotate_x(stack_a, stack_b, "rr");
	}
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		rotate_x(stack_a, stack_b, "rrr");
	}
}
