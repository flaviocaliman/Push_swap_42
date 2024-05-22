/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:33:59 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/22 21:07:44 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_main_index(t_stack *stack_a, int size)//walter's code
{
	t_stack	*tmp;
	t_stack	*max_add;
	int		max_nbr;

	while (size--)
	{
		tmp = stack_a;
		max_nbr = INT_MIN;
		max_add = NULL;
		while (tmp)
		{
			if (tmp->nbr == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			else if (tmp->nbr > max_nbr && tmp->index == 0)
			{
				max_nbr = tmp->nbr;
				max_add = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (max_add)
			max_add->index = size + 1;
	}
}

t_stack	*stack_new_node(int nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->index = 0;
	new_node->position = -1;
	new_node->where_fit = -1;
	new_node->mv_a = -1;
	new_node->mv_b = -1;
	new_node->next = NULL;
	return (new_node);
}

static void	stack_add_end(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp;

	if (!new_node)
		return ;
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

t_stack	*init_stack_a(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nbr;
	int			i;

	stack_a = NULL;
	nbr = 0;
	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_exit(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new_node((int)nbr);
		else
			stack_add_end(&stack_a, stack_new_node((int)nbr));
		i++;
	}
	return (stack_a);
}
