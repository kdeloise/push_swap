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

void	ft_sa(t_stack **stack_a)
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
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
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
	ft_printf("sb\n");
}

void	ft_ss(t_fl	*stacks)
{
	ft_sa(&stacks->a);
	ft_sb(&stacks->b);
	ft_printf("ss\n");
}
