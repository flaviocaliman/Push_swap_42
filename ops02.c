/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:49:50 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/15 18:30:22 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;
	int	i;
	int	pushed;

	size = stack_len(*stack_a);
	i = 0;
	pushed = 0;
	while (i < size && pushed < size / 2 && size > 6)
	{
		if ((*stack_a)->index <= size / 2)
		{
			swap_x(stack_b, stack_a, "pb");
			pushed++;
		}
		else
			rotate_x(stack_a, NULL, "ra");
		i++;
	}
	while (size - pushed > 3)
	{
		swap_x(stack_b, stack_a, "pb");
		pushed++;
	}
	small_sort(stack_a);
}

//retorna a posição do nó com maior indice a ser movido
int	get_a_position(t_stack_node **stack_a, int b_index, int max, int a_position)
{
	t_stack_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < max)
		{
			max = tmp->index;
			a_position = tmp->position;
		}
		tmp = tmp->next;
	}
	if (max != INT_MAX)
		return (a_position);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < max)
		{
			max = tmp->index;
			a_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (a_position);
}

//atribui valores de posição para cada nó da pilha
void	get_stack_positions(t_stack_node **stack)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

//determina onde cada nó da stack_b deve ser inserido na stack_a
void	where_fit_in_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*b;
	int				a_position;

	b = *stack_b;
	get_stack_positions(stack_a);
	get_stack_positions(stack_b);
	a_position = 0;
	while (b)
	{
		a_position = get_a_position(stack_a, b->index, INT_MAX, a_position);
		b->where_fit = a_position;
		b = b->next;
	}
}

void	big_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_to_b(stack_a, stack_b);
	while (stack_b)
	{
		where_fit_in_a(stack_a, stack_b);
		calculate_moves(stack_a, stack_b);
		less_moves_sort(stack_a, stack_b);
	}
	if (is_sorted(*stack_a))
		last_rotates(stack_a);
}
