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
	int					pos;   //may be '+' or '-'
	struct s_stack		*next;
}						t_stack;

typedef	struct			s_steps
{
	int					count_a;
	int					count_b;
}						t_steps;

typedef struct			s_fl
{
	int					flag_for_print;
	int					first;
	int 				minsteps;
	int					count_step;
	int					last_data;
	int					min; //min_of_stack
	int					max; //max_of_stack
	int					med; //med_of_stack
	int					count_a; //size_of_stack A
	int					count_b; //size_of_stack B
	int					*sorted_stack;
    t_stack             *a;
    t_stack             *b;
}						t_fl;

int						atoi_for_ps(const char *str);
int						len_nbr(char *str);
int						validelemet(char *stack1);
t_fl					validate_of_stack(char *str);
void 					quicksort(int *number, int first, int last);
t_fl					check_double(char *str);
t_stack					*create_stack_a(int *stack_a, int size_of_stack);
void					create_stack_b(t_fl *fl);
void					print_stack(t_stack	*stack);
void					ft_sa(t_stack **stack_a, t_fl	*fl);
void					ft_sb(t_stack **stack_b, t_fl	*fl);
void					ft_ss(t_fl	*stacks, t_fl	*fl);
void					ft_ra(t_stack **stack_a, t_fl	*fl);
void					ft_rb(t_stack **stack_b, t_fl	*fl);
void					ft_rr(t_fl *stacks, t_fl	*fl);
void					ft_rra(t_stack **stack_a, t_fl	*fl);
void					ft_rrb(t_stack **stack_b, t_fl	*fl);
void					ft_rrr(t_fl *stacks, t_fl	*fl);
void					ft_pa(t_stack **stack_a, t_stack **stack_b, t_fl *fl);
void					ft_pb(t_stack **stack_a, t_stack **stack_b, t_fl *fl);
void					push_swap_sort(t_fl *fl);

#endif
