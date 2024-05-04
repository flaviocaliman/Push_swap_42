/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:59 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/03 10:38:18 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *s)
{
    long    result;
    int     sign;
}

void    init_stack_a(t_stack_node **a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while (argv[i])
    {
        if (error_syntax(argv[1]))
            free_erros(a);
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_erros(a);
        if (error_duplicate(*a, (int)n))
            free_erros(a);
        append_node(a, (int)n);
        i++;
    }
}