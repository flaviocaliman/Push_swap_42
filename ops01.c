/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:03:12 by caliman           #+#    #+#             */
/*   Updated: 2024/05/15 18:28:53 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap(t_stack_node **stack)
{
    t_stack_node    *tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

static void    push(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node    *tmp;

    if (!*stack_b)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void    swap_x(t_stack_node **stack_a, t_stack_node **stack_b, char *str)
{
    if (ft_strcmp(str, "sa") == 0)
        swap(stack_a);
    else if (ft_strcmp(str, "sb") == 0)
        swap(stack_b);
    else if (ft_strcmp(str, "ss") == 0)
    {
        swap(stack_a);
        swap(stack_b);
    }
    if (ft_strcmp(str, "pa") == 0)
        push(stack_a, stack_b);
    else if (ft_strcmp(str, "pb") == 0)
        push(stack_b, stack_a);
    ft_putstr(str);
    ft_putstr("\n");
}

void    small_sort(t_stack_node **stack)
{
    int max_index;

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

static void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		swap_x(stack_a, NULL, "sa");
	else if (size == 3)
		small_sort(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		big_sort(stack_a, stack_b);
}
