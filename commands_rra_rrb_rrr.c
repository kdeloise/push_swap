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

void ft_rra(t_stack **stack_a) // stack_a = |1| -> |2| -> |3| -> |4| -> NULL
{
	t_stack		*start;
	t_stack		*last;
	t_stack		*prelast;

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
	ft_printf("rra\n");
}

void ft_rrb(t_stack **stack_b) // stack_a = |1| -> |2| -> |3| -> |4| -> NULL
{
	t_stack		*start;
	t_stack		*last;
	t_stack		*prelast;

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
	ft_printf("rrb\n");
}

void					ft_rrr(t_fl *stacks)
{
	ft_rra(&stacks->a);
	ft_rrb(&stacks->b);
	ft_printf("rrr\n");
}