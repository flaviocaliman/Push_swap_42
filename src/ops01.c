/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:03:12 by caliman           #+#    #+#             */
/*   Updated: 2024/05/21 12:09:41 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  get_max_index(t_stack_node *stack)
{
	int             max_index;
	t_stack_node    *tmp;

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

void    small_sort(t_stack_node **stack)
{
	int max_index;

	if (is_sorted(*stack))//utils02.c
		return ;
	max_index = get_max_index(*stack);
	if ((*stack)->index == max_index)
		rotate_x(stack, NULL, "ra");//rotate01.c
	else if ((*stack)->next->index == max_index)
		rotate_x(stack, NULL, "rra");//rotate01.c
	if ((*stack)->index > (*stack)->next->index)
		swap_x(stack, NULL, "sa");//swap.c
}

void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))//utils02.c
		swap_x(stack_a, NULL, "sa");//swap.c
	else if (size == 3)
		small_sort(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))//utils02.c
		big_sort(stack_a, stack_b);//ops02.c
}
