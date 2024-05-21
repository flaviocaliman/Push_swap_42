/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliman <caliman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:08:09 by fgomes-c          #+#    #+#             */
/*   Updated: 2024/05/19 11:43:06 by caliman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_stack_node
{
    int					nbr;
    int					index;
    int					position;
    int					where_fit;
    int					mv_a;
    int					mv_b;
    struct s_stack_node	*next;
}   t_stack_node;

//Utils01
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
int				stack_len(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			error_exit(t_stack_node **a, t_stack_node **b);

//Utils02
long int		ft_atoi(const char *s);
int				is_sorted(t_stack_node *stack);
int				absolute(int n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);

//Operations01
void			small_sort(t_stack_node **stack);
void			push_swap(t_stack_node **stack_a, t_stack_node **stack_b, int size);

//Operations02
void			big_sort(t_stack_node **stack_a, t_stack_node **stack_b);

//Operations03
void			calculate_moves(t_stack_node **stack_a, t_stack_node **stack_b);
void			less_moves_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void			last_rotates(t_stack_node **stack_a);

//Params
//char			*remove_extra_zero(char *str);
int				is_nbr(char *str);
int				check_params(char **argv);

//Stack_init
void			get_main_index(t_stack_node *stack, int size);
t_stack_node	*init_stack_a(int argc, char **argv);


//Rotate01
void			rotate_x(t_stack_node **stack_a, t_stack_node **stack_b, char *str);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, int *mv_a, int *mv_b);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, int *mv_a, int *mv_b);

//Rotate02
void			rotate_a(t_stack_node **stack_a, int *mv_a);
void	 		rotate_b(t_stack_node **stack_b, int *mv_b);

//Swap
void			swap_x(t_stack_node **stack_a, t_stack_node **stack_b, char *str);

#endif