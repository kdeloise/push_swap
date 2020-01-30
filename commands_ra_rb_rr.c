/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ra_rb_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 07:10:28 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/26 07:10:30 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack		*first;
	t_stack		*last;
	t_stack		*start;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = (*stack_a);			//first = |1| -> |2| -> |3| -> NULL
	start = (*stack_a)->next;	//start = |2| -> |3| -> NULL
	while(*stack_a)
	{
		if (!(*stack_a)->next)
			last = *stack_a; //last = |3| -> NULL
		(*stack_a) = (*stack_a)->next;
	}
	first->next = NULL;       //first = |1| -> NULL
	last->next = first;       //last = |3| -> |1| -> NULL
	(*stack_a) = start;		  //*stack_a = |2| -> |3| -> |1| -> NULL
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	t_stack		*first;
	t_stack		*last;
	t_stack		*start;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = (*stack_b);			//first = |1| -> |2| -> |3| -> NULL
	start = (*stack_b)->next;	//start = |2| -> |3| -> NULL
	while(*stack_b)
	{
		if (!(*stack_b)->next)
			last = *stack_b; //last = |3| -> NULL
		(*stack_b) = (*stack_b)->next;
	}
	first->next = NULL;       //first = |1| -> NULL
	last->next = first;       //last = |3| -> |1| -> NULL
	(*stack_b) = start;		  //*stack_b = |2| -> |3| -> |1| -> NULL
	ft_printf("rb\n");
}

void	ft_rr(t_fl *stacks)
{
	ft_ra(&stacks->a);
	ft_rb(&stacks->b);
	ft_printf("rr\n");
}