/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:02 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/14 20:42:28 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_swap(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		swap_move(stack_a, NULL, "sa");
	else if (size == 3)
		small_sort(stack_a);
	//else if (size > 3 && !is_sorted(*stack_a))
	//	big_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_stack_node    *stack_a;
    t_stack_node    *stack_b;
    int             *size;

    if (argc < 2)
        return (0);
    if (!check_params(argc, argv))
        error_exit (NULL, NULL);
    remove_extra_zero(argv);
    stack_a = init_stack_a(argc, argv);
    stack_b = NULL;
    size = stack_len(stack_a);
    get_main_index(stack_a, size);
    push_swap(&stack_a, &stack_b, size);
}
 