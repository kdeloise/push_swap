/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:12:22 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/03 17:49:59 by kdeloise         ###   ########.fr       */
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

int						atoi_for_ps(const char *str);
int						len_nbr(char *str);
int						validelemet(char *stack1);
void					validate_of_stack(char *str);
void					check_double(char *str);
void					create_stack_a(int *stack_a, int size_of_stack);

#endif
