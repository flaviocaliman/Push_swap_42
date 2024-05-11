/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:59 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/10 23:46:32 by caliman          ###   ########.fr       */
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

t_stack_node	*init_stack_a(int argc, char **argv)
{
	t_stack_node	*stack_a;
	long int		nbr;
	int				i;

	stack_a = NULL;
	i = argc - 1;
	while (i > 0)
	{
		if (!is_nbr(argv[i]))
			error_exit(&stack_a, NULL);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_exit(&stack_a, NULL);
		if (!stack_a)
			stack_a = stack_new(nbr);
		else
			stack_add_front(&stack_a, stack_new(nbr));
		i--;
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