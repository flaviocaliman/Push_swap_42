/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:59 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/14 19:22:56 by caliman          ###   ########.fr       */
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

static t_stack_node	*stack_new_node(int nbr)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		error_exit(NULL, NULL);
	new_node->nbr = nbr;
	new_node->index = 0;
	new_node->position = -1;
	new_node->where_fit = -1;
	new_node->mv_a = -1;
	new_node->mv_b = -1;
	new_node->next = NULL;
	return (new_node);
}

static void	stack_add_end(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*tmp;
	
	if (!new_node)
		error_exit(stack, NULL);
	if (!*stack)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
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
			stack_a = stack_new_node(nbr);
		else
			stack_add_end(&stack_a, stack_new_node((int)nbr));
		i--;
	}
	return (stack_a);
}
