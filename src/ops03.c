/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops03.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:09:09 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/21 14:10:41 by fgomes-c         ###   ########.fr       */
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
	stack_a_len = stack_len(a);//utils01.c
	stack_b_len = stack_len(b);//utils01.c
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

void	less_moves_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*b;
	int				min_moves;
	int				mv_a;
	int				mv_b;

	b = *stack_b;
	min_moves = INT_MAX;
	while (b)
	{
		if (absolute(b->mv_a) + absolute(b->mv_b) < absolute(min_moves))//utils02.c
		{
			min_moves = absolute(b->mv_a) + absolute(b->mv_b);//utils02.c
			mv_a = b->mv_a;
			mv_b = b->mv_b;
		}
		b = b->next;
	}
	if (mv_a < 0 && mv_b < 0)
		rrr(stack_a, stack_b, &mv_a, &mv_b);//rotate01.c
	else if (mv_a > 0 && mv_b > 0)
		rr(stack_a, stack_b, &mv_a, &mv_b);//rotate01.c
	rotate_a(stack_a, &mv_a);//rotate02.c
	rotate_b(stack_b, &mv_b);//rotate02.c
	swap_x(stack_a, stack_b, "pa");//swap.c
}

int	get_lower_position(t_stack_node *stack, int size)
{
	t_stack_node	*tmp;
	int				lower_position;

	tmp = stack;
	lower_position = 0;
	while (tmp)
	{
		if (tmp->position < lower_position)
			lower_position = tmp->position;
		tmp = tmp->next;
	}
	if (lower_position < 0)
		lower_position += size;
	return (lower_position);
}

void	last_rotates(t_stack_node **stack_a)
{
	int	size;
	int	lower_position;

	size = stack_len(*stack_a);//utils01.c
	lower_position = get_lower_position(*stack_a, size);
	if (lower_position <= size / 2)
		while (lower_position--)
			rotate_x(stack_a, NULL, "ra");//rotate01.c
	else
		while (lower_position++ < size)
			rotate_x(stack_a, NULL, "rra");//rotate01.c
}