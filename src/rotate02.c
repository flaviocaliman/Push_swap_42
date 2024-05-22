/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:32:52 by caliman           #+#    #+#             */
/*   Updated: 2024/05/22 21:03:30 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a, int *mv_a)
{
	while (*mv_a)
	{
		if (*mv_a > 0)
		{
			rotate_x(stack_a, NULL, "ra");
			(*mv_a)--;
		}
		else if (*mv_a < 0)
		{
			rotate_x(stack_a, NULL, "rra");
			(*mv_a)++;
		}
	}
}

void	rotate_b(t_stack **stack_b, int *mv_b)
{
	while (*mv_b)
	{
		if (*mv_b > 0)
		{
			rotate_x(NULL, stack_b, "rb");
			(*mv_b)--;
		}
		else if (*mv_b < 0)
		{
			rotate_x(NULL, stack_b, "rrb");
			(*mv_b)++;
		}
	}
}
