/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:02 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/21 01:10:18 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				size;

	if (argc < 2)
		return (0);
	if (!check_params(argv))//params.c
		error_exit (NULL, NULL);//utils01.c
	stack_a = init_stack_a(argc, argv);//stack_init.c
	stack_b = NULL;
	size = stack_len(stack_a);//utils01.c
	get_main_index(stack_a, size); //stack_init.c
	push_swap(&stack_a, &stack_b, size);//ops01.c
	free_stack(&stack_a);//utils01.c
	free_stack(&stack_b);//utils01.c
}
 