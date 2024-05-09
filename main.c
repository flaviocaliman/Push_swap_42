/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:02 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/09 23:57:02 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    push_
}
