/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:04:17 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/26 10:04:26 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// stack_a = |1| -> |2| -> |3 | -> NULL
// stack_b = |8| -> |9| -> |10| -> NULL
void ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*first_b;

	first_b = (*stack_b)->next;			//|9| -> |10| -> NULL
	(*stack_b)->next = (*stack_a);		//|8| -> |1 | -> |2| -> |3 | -> NULL
	(*stack_a) = (*stack_b);			//|8| -> |1 | -> |2| -> |3 | -> NULL
	(*stack_b) = first_b;				//|9| -> |10| -> NULL
	ft_printf("pa\n");
}

void ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*first_a;

	first_a = (*stack_a)->next;			//|2| -> |3| -> NULL
	(*stack_a)->next = (*stack_b);		//|1| -> |8 | -> |9| -> |10| -> NULL
	(*stack_b) = (*stack_a);			//|1| -> |8 | -> |9| -> |10| -> NULL
	(*stack_a) = first_a;				//|2| -> |3| -> NULL
	ft_printf("pb\n");
}