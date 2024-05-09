/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:55:48 by caliman           #+#    #+#             */
/*   Updated: 2024/05/09 01:08:39 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  is_nbr(char *str)
{
    while (*str)
    {
        if (*str == '-' || *str == '+')
            str++;
        while (*str)
        {
            if (!(*str >= '0' && *str <= '9'))
                return (0);
            str++;
        }
    }
    return (1);
}

static int  is_int(char *str)
{
    long    n;

    n = ft_atol(str);
    if (n > INT_MAX || n < INT_MIN)
        return (0);
    return (1);
}

static int  is_dup(char **str, int i)
{
    int j;

    j = i + 1;
    while (str[j])
    {
        if (ft_atoi(str[i]) == ft_atoi(str[j]))
            return (0);
        j++;
    }
    return (1);
}

{
    if (*str >= '0' && *str <= '9')
    {
        while (*str >= '0' && *str <= '9')
            str++;
        if(*str)
            return (0);
        return (1);
    }
    return (0);
}

int check_params(int argc, char **argv)
{
    int i;

    i = -1;
    while (++i < argc)
        if (!is_nbr(argv[i])  || !is_int(argv[i]) || !is_dup(argv, i))
            return (0);
}