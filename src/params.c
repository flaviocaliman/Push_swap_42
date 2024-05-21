/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:55:48 by caliman           #+#    #+#             */
/*   Updated: 2024/05/19 11:42:01 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *remove_extra_zero(char *str)
{
    int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
        str[j++] = str[i++];
	while (str[i] == '0')
		i++;
	if (!str[i])
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	else
	{
		while (str[i])
			str[j++] = str[i++];
		str[j] = '\0';
		return (str);
	}
}

int	is_nbr(char *str)
{
	if (*str == '\0')
		return (false);
	if (*str == '-' && ft_strlen(str) > 1)
		str++;
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}

/* Gabriel's version
int is_nbr(char *str)
{
	int			i;
	long int	nbr;
	
	i = 0;
	nbr = ft_atoi(str);
	if (nbr > INT_MAX)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (str[0] == '-' || str[0] == '+')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	i++;
}
*/

/*
int  is_nbr(char *str)
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
}*/

bool	is_int(char *str)
{
	int		signal;
	long	res;

	res = 0;
	signal = 1;
	if (*str == '-')
	{
		signal = -1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10 + *(str++) - '0';
	res *= signal;
	return (res >= INT_MIN && res <= INT_MAX);
}

static int  is_dup(char **argv)
{
    int		i;
	int		j;
	long	temp;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		temp = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == temp)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*bool	is_dup(char **argv, int pos)
{
	int	i;
	int	current;

	i = 0;
	current = ft_atoi(argv[pos]);
	while (i < pos)
	{
		if (ft_atoi(argv[i++]) == current)
			return (true);
	}
	return (false);
}*/

/*bool check_params(int argc, char **argv)
{
    int i;

    i = -1;
    while (++i < argc)
	{
        if (!is_nbr(argv[i])  || !is_int(argv[i]) || is_dup(argv, i))
            return (false);
	}
    return (true);
}*/

int	check_params(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_nbr(argv[i]))
			return (0);
		if (!is_int(argv[i]))
			return (0);
		if (argv[i][0] == '0' || argv[i][1] == '0')
			argv[i] = remove_extra_zero(argv[i]);
		i++;
	}
	if (is_dup(argv) || !argv[1][0])
		return (0);
	return (1);
}