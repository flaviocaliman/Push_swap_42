/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops01.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:03:12 by caliman           #+#    #+#             */
/*   Updated: 2024/05/14 23:58:20 by caliman          ###   ########.fr       */
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

void    swap_move(t_stack_node **stack_a, t_stack_node **stack_b, char *str)
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
    
}