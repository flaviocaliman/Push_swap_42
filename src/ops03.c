/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:09:09 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/22 20:28:59 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calcula a quantidade de movimentos necessários para mover cada nó de b para a
void	calculate_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		stack_a_len;
	int		stack_b_len;

	a = *stack_a;
	b = *stack_b;
	stack_a_len = stack_len(a);
	stack_b_len = stack_len(b);
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

void	less_moves_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		min_moves;
	int		mv_a;
	int		mv_b;

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
	rotate_a(stack_a, &mv_a);
	rotate_b(stack_b, &mv_b);
	swap_x(stack_a, stack_b, "pa");
}

int	get_lower_position(t_stack **stack)
{
	t_stack	*tmp;
	int		low_index;
	int		low_position;

	tmp = *stack;
	low_index = INT_MAX;
	get_stack_positions(stack);
	low_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < low_index)
		{
			low_index = tmp->index;
			low_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (low_position);
}

void	last_rotates(t_stack **stack_a)
{
	int	size;
	int	lower_position;

	size = stack_len(*stack_a);
	lower_position = get_lower_position(stack_a);
	if (lower_position <= size / 2)
		while (lower_position--)
			rotate_x(stack_a, NULL, "ra");
	else
		while (lower_position++ < size)
			rotate_x(stack_a, NULL, "rra");
}
