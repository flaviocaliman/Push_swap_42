/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:08:09 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/07 21:15:13 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
    int                 nbr;
    int                 index;
    int                 position;
    int                 where_fit;
    int                 mv_a;
    int                 mv_b;
    struct s_stack_node *next;
}   t_stack_node;

//Handle erros

//Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

#endif