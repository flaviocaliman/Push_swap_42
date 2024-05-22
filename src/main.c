/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:02 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/22 20:42:05 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (!check_params(argv))
		error_exit(NULL, NULL);
	stack_a = init_stack_a(argc, argv);
	stack_b = NULL;
	size = stack_len(stack_a);
	get_main_index(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
