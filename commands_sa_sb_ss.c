/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:51:21 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/19 18:17:16 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sa(t_stack **stack_a, t_fl	*fl)
{
	t_stack *first;
	t_stack *second;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = (*stack_a);
	second = (*stack_a)->next;
	first->next = NULL;
	(*stack_a) = second;
	first->next = (*stack_a)->next;
	(*stack_a)->next = first;
	if (fl->flag_for_print == 0)
		ft_printf("sa\n");
	fl->flag_for_print = 0;
	fl->count_step++;
}

void	ft_sb(t_stack **stack_b, t_fl	*fl)
{
	t_stack *first;
	t_stack *second;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = (*stack_b);
	second = (*stack_b)->next;
	first->next = NULL;
	(*stack_b) = second;
	first->next = (*stack_b)->next;
	(*stack_b)->next = first;
	if (fl->flag_for_print == 0)
		ft_printf("sb\n");
	fl->flag_for_print = 0;
	fl->count_step++;
}

void	ft_ss(t_fl	*stacks, t_fl	*fl)
{
	fl->flag_for_print = 1;
	ft_sa(&stacks->a, fl);
	fl->flag_for_print = 1;
	ft_sb(&stacks->b, fl);
	ft_printf("ss\n");
	fl->count_step++;
}
