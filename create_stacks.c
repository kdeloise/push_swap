/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:43:24 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/12 18:00:52 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack		*create_stack_a(int *stack_a, int size_of_stack)
{
	int			i;
	t_stack		*a;
	t_stack		*start;

	i = 0;
	if (!(a = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	start = a;
	while(i < size_of_stack)
	{
		if (i < size_of_stack - 1)
		{
			if (!(a->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		}
		a->data = stack_a[i];
		if (i == (size_of_stack - 1))
			a->next = NULL;
		else
			a = a->next;
		i++;
	}
	a = start;
	i = 0;
	while(a)
	{
		ft_printf("list stack[%d] = %d\n", i, a->data);
		a = a->next;
		i++;
	}
	a = start;
	return(a);
}

void		create_stack_b(t_fl *fl)
{
	t_stack	*start_b;
	t_stack	*start_a;

	if(!(fl->b = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	fl->b->data = 0;
	start_b = fl->b;
	start_a = fl->a;
	while(fl->a)
	{
		if (fl->a->next == NULL)
			fl->b->next = NULL;
		else if (!(fl->b->next = (t_stack *)malloc(sizeof(t_stack))))
			exit(1);
		fl->b->data = 0;
		fl->a = fl->a->next;
		fl->b = fl->b->next;
	}
	fl->b = start_b;
	fl->a = start_a;
}

void		print_stack(t_stack	*stack)
{
	ft_printf("\n-----------\nit's data of stack\n-----------\n");
	while(stack)
	{
		ft_printf("|%d| ", stack->data);
		stack = stack->next;
	}
}