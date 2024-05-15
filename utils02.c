/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:57:11 by caliman           #+#    #+#             */
/*   Updated: 2024/05/15 17:26:33 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *s)
{
	long int	r;
	int			sg;

	r = 0;
	sg = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = (r * 10) + (*s - '0');
		s++;
	}
	return (sg * r);
}

int	is_sorted(t_stack_node *stack)
{
    t_stack_node    *tmp;

    tmp = stack;
    while (tmp->next)
    {
        if (tmp->nbr > tmp->next->nbr)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int	absolute(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}