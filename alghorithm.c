/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:10:56 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/12 21:32:37 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort3elements(t_fl *fl)
{
	//t_stack		*start;
	int			i;

	i = 0;
//	ft_printf("\n\n------start_a_in sort---------\n");
//	print_stack(fl->a);
//	ft_printf("min = /%d/\nmax = /%d/\nmed = /%d/\n\n", (fl)->min, (fl)->max, (fl)->med);
	while (i < fl->count)
	{
		if (fl->a->data == fl->sorted_stack[i])
		{
			ft_pb(&fl->a, &fl->b);
			print_stack(fl->a);
			print_stack(fl->b);
			i++;
		}
		ft_ra(&fl->a);
	}
	i = 0;
	while (fl->b)
	{
		ft_pa(&fl->a, &fl->b);
		print_stack(fl->b);
		print_stack(fl->a);
	}
}

void	push_swap_sort(t_fl *fl)
{
	if (fl->count > 0)
		ft_sort3elements(fl);
	else
		;
}