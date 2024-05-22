/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:55:48 by caliman           #+#    #+#             */
/*   Updated: 2024/05/22 20:53:43 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*remove_extra_zero(char *str)
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
		return (0);
	if (*str == '-' && ft_strlen(str) > 1)
		str++;
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}

static int	is_dup(char **argv)
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

int	check_params(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_nbr(argv[i]))
			return (0);
		if (argv[i][0] == '0' || argv[i][1] == '0')
			argv[i] = remove_extra_zero(argv[i]);
		i++;
	}
	if (is_dup(argv) || !argv[1][0])
		return (0);
	return (1);
}
