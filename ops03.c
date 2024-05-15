/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:09:09 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:27 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calcula a quantidade de movimentos necessários para mover cada nó de b para a
void	calculate_moves(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_a_len;
	int				stack_b_len;

	a = *stack_a;
	b = *stack_b;
	stack_a_len = stack_len(*stack_a);
	stack_b_len = stack_len(*stack_b);
	while (b)
	{
		b->mv_b = b->position;
		if (b->position > stack_b_len / 2)
			b->mv_b = (stack_b_len - b->position) * -1;
		b->mv_a = b->where_fit;
		if (b->where_fit > stack_a_len / 2)
			b->mv_a = (stack_a_len - b->where_fit) * -1;
		b = b->next;
	}
}

static void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		rotate_x(stack_a, stack_b, "rr");
	}
}

static void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		rotate_x(stack_a, stack_b, "rrr");
	}
}

void	less_moves(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*b;
	int				min_moves;
	int				mv_a;
	int				mv_b;

	b = *stack_b;
	min_moves = INT_MAX;
	while (b)
	{
		if (absolute(b->mv_a) + absolute(b->mv_b) < absolute(min_moves))
		{
			min_moves = absolute(b->mv_a) + absolute(b->mv_b);
			mv_a = b->mv_a;
			mv_b = b->mv_b;
		}
		b = b->next;
	}
	if (mv_a < 0 && mv_b < 0)
		rrr(stack_a, stack_b, &mv_a, &mv_b);
	else if (mv_a > 0 && mv_b > 0)
		rr(stack_a, stack_b, &mv_a, &mv_b);
}
