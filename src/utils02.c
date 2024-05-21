/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:57:11 by caliman           #+#    #+#             */
/*   Updated: 2024/05/18 14:03:32 by caliman          ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
