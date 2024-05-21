/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:23:28 by caliman           #+#    #+#             */
/*   Updated: 2024/05/21 14:33:46 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack_node *stack)
{
    int	tmp;

	if (!stack || !(stack)->next)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void    push(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node    *tmp;

    if (!stack_a)
        return ;
    tmp = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = tmp;
}

void    swap_x(t_stack_node **stack_a, t_stack_node **stack_b, char *str)
{
    if (ft_strcmp(str, "sa") == 0)//utils01.c
        swap(*stack_a);
    else if (ft_strcmp(str, "sb") == 0)//utils01.c
        swap(*stack_b);
    else if (ft_strcmp(str, "ss") == 0)//utils01.c
    {
        swap(*stack_a);
        swap(*stack_b);
    }
    if (ft_strcmp(str, "pa") == 0)//utils01.c
        push(stack_b, stack_a);
    else if (ft_strcmp(str, "pb") == 0)//utils01.c
        push(stack_a, stack_b);
    ft_putstr(str);//utils01.c
    ft_putstr("\n");//utils01.c
}
