/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:12:22 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/12 22:00:19 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_fl
{
	int					min; //min_of_stack
	int					max; //max_of_stack
	int					med; //med_of_stack
	int					count; //size_of_stack
    t_stack             *a;
    t_stack             *b;
}						t_fl;

int						atoi_for_ps(const char *str);
int						len_nbr(char *str);
int						validelemet(char *stack1);
t_fl					validate_of_stack(char *str);
t_fl					check_double(char *str);
t_stack					*create_stack_a(int *stack_a, int size_of_stack);
void                    create_stack_b(t_fl *fl);
void					print_stack(t_stack	*stack);
void                    ft_sa(t_stack **stack_a);
void                    ft_sb(t_stack **stack_b);
void					ft_ss(t_fl	*stacks);
void					ft_ra(t_stack **stack_a);
void					ft_rb(t_stack **stack_b);
void					ft_rr(t_fl *stacks);
void					ft_rra(t_stack **stack_a);
void					ft_rrb(t_stack **stack_b);
void					ft_rrr(t_fl *stacks);

#endif
