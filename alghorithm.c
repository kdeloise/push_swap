/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:10:56 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/12 21:32:37 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	zero_function(t_fl	*fl, t_steps *step)
{
	step->count_a = 0;
	step->count_b = 0;
}

void	ft_position(t_fl	*fl)
{
	int		med;
	int		i_plus;
	int 	i_minis;
	t_stack *start_a;
	t_stack	*start_b;

	i_plus = 0;
	med = fl->count_a / 2;
	i_minis = med * -1;
	start_a = fl->a;
	if (fl->count_a % 2 != 0)
		med++;
	while(fl->a)
	{
		if(i_plus < med)
			fl->a->pos = i_plus++;
		else
			fl->a->pos = i_minis++;
		fl->a = fl->a->next;
	}
	fl->a = start_a;

	i_plus = 0;
	med = fl->count_b / 2;
	i_minis = med * -1;
	start_b = fl->b;
	if (fl->count_b % 2 != 0)
		med++;
	while(fl->b)
	{
		if(i_plus < med)
			fl->b->pos = i_plus++;
		else
			fl->b->pos = i_minis++;
		fl->b = fl->b->next;
	}
	fl->b = start_b;
}

void	create_stacks_for_start(t_fl	*fl)
{
	while(fl->count_a > 2)
	{
		if(fl->a->data == fl->max || fl->a->data == fl->min)
			ft_ra(&fl->a, fl);
		else if(fl->a->data <= fl->med)
			ft_pb(&fl->a, &fl->b, fl);
		else
		{
			ft_pb(&fl->a, &fl->b, fl);
			ft_rb(&fl->b, fl);
		}
		if (fl->a->data < fl->a->next->data)
			ft_sa(&fl->a, fl);
	}
}

void	ft_check_last_element(t_fl	*fl)
{
	t_stack	*start;

	start = fl->a;
	while(fl->a)
	{
		if (fl->a->next == NULL)
		{
			fl->last_data = fl->a->data;
			break ;
		}
		fl->a = fl->a->next;
	}
	fl->a = start;
}

int	un_steps(int pos)
{
	int un_pos;

	if (pos < 0)
		un_pos = pos * -1;
	else
		un_pos = pos;
	return (un_pos);
}

void	ft_find_optimal_position(t_fl	*fl, t_steps	*step)
{
	t_stack			*start;
//	unsigned int 	step_a;
//	unsigned int	step_b;

	start = fl->a;
	while(fl->a && fl->a->next)
	{
		if(fl->b->data > fl->a->data && fl->b->data < fl->a->next->data)
		{
			if (fl->first == 0)
			{
				fl->minsteps = un_steps(fl->a->pos) + 1 + un_steps(fl->b->pos);
				step->count_b = fl->b->pos;
				step->count_a = fl->a->pos + 1;
				fl->first = 1;
			}
			else if (fl->minsteps > un_steps(fl->a->pos) + 1 + un_steps(fl->b->pos))
			{
				fl->minsteps = un_steps(fl->a->pos) + 1 + un_steps(fl->b->pos);
				step->count_b = fl->b->pos;
				step->count_a = fl->a->pos + 1;
			}
			break ;
		}
		fl->a = fl->a->next;
	}
	fl->a = start;
}

int		ft_min_steps(t_fl	*fl, t_steps	*step)
{
	int	step_a;
	int	step_b;
	int	minsteps;

	if (fl->a->pos > 0)
		step_a = fl->a->pos;
	else
		step_a = fl->a->pos * -1;
	if (fl->b->pos > 0)
		step_b = fl->b->pos;
	else
		step_b = fl->b->pos * -1;
	minsteps = step_a + step_b;
	return (minsteps);
}

void			count_of_steps(t_fl	*fl, t_steps *step)
{
	t_stack				*start_a;
	t_stack				*start_b;

	start_a = fl->a;
	start_b = fl->b;
	zero_function(fl, step);
	fl->first = 0;
	while(fl->b)
	{
		while(fl->a)
		{
			if(fl->b->data < fl->a->data)
			{
				if (fl->first == 0)
				{
					ft_check_last_element(fl);
					if (fl->b->data > fl->last_data)
					{
						fl->minsteps = un_steps(fl->a->pos) + un_steps(fl->b->pos);
						step->count_b = fl->b->pos;
						step->count_a = fl->a->pos;
					}
					else if (fl->b->data < fl->last_data)
					{
						ft_find_optimal_position(fl, step);
					}
					fl->first = 1;
				}
				else if (fl->b->data > fl->last_data)
				{
					if (fl->minsteps > un_steps(fl->a->pos) + un_steps(fl->b->pos))
					{
						fl->minsteps = un_steps(fl->a->pos) + un_steps(fl->b->pos);
						step->count_b = fl->b->pos;
						step->count_a = fl->a->pos;
					}
				}
				else if (fl->b->data < fl->last_data)
				{
					ft_find_optimal_position(fl, step);
				}
			}
			else
			{
				if (fl->first == 0)
					ft_check_last_element(fl);
				ft_find_optimal_position(fl, step);
			}
			fl->last_data = fl->a->data;
			fl->a = fl->a->next;
			if (fl->minsteps == 0)
				break ;
		}
		if (fl->minsteps == 0)
			break ;
		fl->a = start_a;
		fl->b = fl->b->next;
	}
	fl->a = start_a;
	fl->b = start_b;
}

void	ft_find_min_number(t_fl	*fl, t_steps	*step)
{
	t_stack	*start;

	start = fl->a;
	while(fl->a)
	{
		if(fl->a->data == fl->min)
		{
			step->count_a = fl->a->pos;
			break ;
		}
		fl->a = fl->a->next;
	}
	fl->a = start;
}

void	push_swap_sort(t_fl	*fl)
{
	t_steps	step;
	int		i;
	int		flag_a;
	int 	flag_b;

	flag_a = 0;
	flag_b = 0;
	fl->count_step = 0;
	fl->count_b = 0;
	fl->flag_for_print = 0;
	if (fl->count_a > 0)
	{
		create_stacks_for_start(fl);
		ft_pa(&fl->a, &fl->b, fl);
		while(fl->b)
		{
			ft_position(fl);
			count_of_steps(fl, &step);
//print_stack(fl->a);
//print_stack(fl->b);
//ft_printf("\n\n\n\n<<<<|%d|>>>>, <<<<|%d|>>>>\n\n\n\n\n", step.count_a, step.count_b);

			i = 0;
			if (step.count_a > 0 && step.count_b > 0)
				while(step.count_a-- > 0 && step.count_b-- > 0)
				{
					ft_rr(fl, fl);
					if (step.count_a == 0 || step.count_b == 0)
						break ;
				}
			else if (step.count_a < 0 && step.count_b < 0)
				while (step.count_a++ < 0 && step.count_b++ < 0)
				{
					ft_rrr(fl, fl);
					if (step.count_a == 0 || step.count_b == 0)
						break ;
				}

			if (step.count_a > 0)
				while(step.count_a-- > 0)
					ft_ra(&fl->a, fl);
			else if (step.count_a < 0)
				while(step.count_a++ < 0)
					ft_rra(&fl->a, fl);

			if (step.count_b > 0)
				while(step.count_b-- > 0)
					ft_rb(&fl->b, fl);
			else if (step.count_b < 0)
				while(step.count_b++ < 0)
					ft_rrb(&fl->b, fl);
			ft_pa(&fl->a, &fl->b, fl);
		}
	}
	ft_position(fl);
	ft_find_min_number(fl, &step);
	i = -1;
	if (step.count_a > 0)
		while(++i < step.count_a)
			ft_ra(&fl->a, fl);
	if (step.count_a < 0)
		while(step.count_a++ < 0)
			ft_rra(&fl->a, fl);
//ft_printf("total_count = %d\n", fl->count_step);
//print_stack(fl->a);
//print_stack(fl->b);
}