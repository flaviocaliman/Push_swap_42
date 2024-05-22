/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:03:12 by caliman           #+#    #+#             */
/*   Updated: 2024/05/22 20:23:39 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *stack)
{
	int			max_index;
	t_stack		*tmp;

	max_index = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

void	small_sort(t_stack **stack)
{
	int	max_index;

	if (is_sorted(*stack))
		return ;
	max_index = get_max_index(*stack);
	if ((*stack)->index == max_index)
		rotate_x(stack, NULL, "ra");
	else if ((*stack)->next->index == max_index)
		rotate_x(stack, NULL, "rra");
	if ((*stack)->index > (*stack)->next->index)
		swap_x(stack, NULL, "sa");
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		swap_x(stack_a, NULL, "sa");
	else if (size == 3)
		small_sort(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		big_sort(stack_a, stack_b);
}
