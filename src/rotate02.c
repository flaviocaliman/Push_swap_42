/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:32:52 by caliman           #+#    #+#             */
/*   Updated: 2024/05/18 11:24:19 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_node **stack_a, int *mv_a)
{
	while (*mv_a)
	{
		if (*mv_a > 0)
		{
			rotate_x(stack_a, NULL, "ra");//rotate01.c
			(*mv_a)--;
		}
		else if (*mv_a < 0)
		{
			rotate_x(stack_a, NULL, "rra");//rotate01.c
			(*mv_a)++;
		}
	}
}

void	rotate_b(t_stack_node **stack_b, int *mv_b)
{
	while (*mv_b)
	{
		if (*mv_b > 0)
		{
			rotate_x(NULL, stack_b, "rb");//rotate01.c
			(*mv_b)--;
		}
		else if (*mv_b < 0)
		{
			rotate_x(NULL, stack_b, "rrb");//rotate01.c
			(*mv_b)++;
		}
	}
}