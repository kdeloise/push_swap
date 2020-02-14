/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rra_rrb_rrr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:11:10 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/26 07:11:11 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_rra(t_stack **stack_a, t_fl	*fl) // stack_a = |1| -> |2| -> |3| -> |4| -> NULL
{
	t_stack		*start;
	t_stack		*last;
	t_stack		*prelast;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	start = (*stack_a);
	while ((*stack_a)->next)
	{
		if (!(*stack_a)->next->next)
		{
			prelast = *stack_a;
		}
		(*stack_a) = (*stack_a)->next;
	}
	last = prelast->next;
	prelast->next = NULL;
	last->next = start;
	(*stack_a) = last;
	if (fl->flag_for_print == 0)
		ft_printf("rra\n");
	fl->flag_for_print = 0;
	fl->count_step++;
}

void ft_rrb(t_stack **stack_b, t_fl	*fl) // stack_a = |1| -> |2| -> |3| -> |4| -> NULL
{
	t_stack		*start;
	t_stack		*last;
	t_stack		*prelast;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	start = (*stack_b);
	while ((*stack_b)->next)
	{
		if (!(*stack_b)->next->next)
		{
			prelast = *stack_b;
		}
		(*stack_b) = (*stack_b)->next;
	}
	last = prelast->next;
	prelast->next = NULL;
	last->next = start;
	(*stack_b) = last;
	if (fl->flag_for_print == 0)
		ft_printf("rrb\n");
	fl->flag_for_print = 0;
	fl->count_step++;
}

void	ft_rrr(t_fl *stacks, t_fl	*fl)
{
	fl->flag_for_print = 1;
	ft_rra(&stacks->a, fl);
	fl->flag_for_print = 1;
	ft_rrb(&stacks->b, fl);
	ft_printf("rrr\n");
	fl->count_step++;
}