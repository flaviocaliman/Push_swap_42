/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:04:04 by caliman           #+#    #+#             */
/*   Updated: 2024/05/09 23:18:34 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
        *stack = tmp;
    }
    *stack = NULL;
}

void    error_exit(t_stack_node **a, t_stack_node **b)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}