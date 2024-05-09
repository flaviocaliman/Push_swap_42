/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:59 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/10 00:34:22 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_main_index(t_stack_node *stack, int size)
{
	t_stack_node	*tmp;
	int				i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = 0;
		tmp = stack;
		while (tmp)
		{
			if (tmp->nbr == i)
				tmp->index = j;
			j++;
			tmp = tmp->next;
		}
		i++;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

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

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}