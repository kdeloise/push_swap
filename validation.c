/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:08:37 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/13 19:42:37 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int sizeof_int(char *stack1)
// {
// 	int i;

// 	i = 0;
// 	while(stack1[i])
// 	{
// 		if (ft_atoi(stack1[i]) > );

// 	}
// }

void quicksort(int *number, int first, int last)
{
	int i, j, pivot, temp;

	if(first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while(i < j)
		{
			while(number[i] <= number[pivot] && i < last)
				i++;
			while(number[j] > number[pivot])
				j--;
			if(i<j)
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}


void	bubble_sort_array(int	*stack_a, int count)
{
	int	i;
	int swp;

	i = 0;
	while(i < count - 1)
	{
		if(stack_a[i] > stack_a[i + 1])
		{
			swp = stack_a[i];
			stack_a[i] = stack_a[i + 1];
			stack_a[i + 1] = swp;
			i = -1;
		}
		i++;
	}
	i = 0;
	ft_printf("\n\n\n");
	while(i < count)
	{
		ft_printf("stack_a[%d] =-><-= %d\n", i, stack_a[i]);
		i++;
	}
}

t_fl    check_double(char *str)
{
	int		*stack_a;
	int		*tmp;
	t_fl    fl;
	int		i;
	int     j;
	t_stack	*a;

	fl.count = len_nbr(str);
	ft_printf("count - %d\n", fl.count);
	stack_a = (int *)malloc(sizeof(int) * fl.count);
	tmp = (int *)malloc(sizeof(int) * fl.count);
	i = 0;
	j = 0;
	while(str[i] != '\0')
	{
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if (str[i] != '\0')
		{
			stack_a[j] = atoi_for_ps(&str[i]);
			tmp[j] = atoi_for_ps(&str[i]);
			ft_printf("stack_a[%d] = %d\n", j, stack_a[j]);
			j++;
		}
		while(ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}
	//bubble_sort_array(stack_a, count);
	quicksort(tmp, 0, fl.count - 1);
	i = 0;
	ft_printf("\n\nsorted array_of_int\n");
	while(i < fl.count)
	{
		ft_printf("stack[%d] = %d\n", i, tmp[i]);
		i++;
	}
	i = 0;
	j = 0;
	while(i < fl.count - 1)
	{
		if (tmp[i] == tmp[i + 1])
		{
			ft_printf("error <double>\n");
			exit (1);
		}
		i++;
	}
	ft_printf("\n\n");
	fl.a = create_stack_a(stack_a, fl.count);
	if (fl.a)
		create_stack_b(&fl);
	ft_printf("\nfl->count = %d\n", fl.count);
	return(fl);
}

t_fl    validate_of_stack(char *str)
{
	int     i;
	t_fl    fl;

	i = 0;
	while(str[i])
	{
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if (str[i] != '\0')
			atoi_for_ps(&str[i]);
		while(ft_isdigit(str[i]) || str[i] == '-')
		{
			if(ft_isdigit(str[i]) && str[i + 1] == '-')
			{
				ft_printf("error <error_pos_minus>\n");
				exit (1);
			}
			i++;
		}
	}
	fl = check_double(str);
    return (fl);
}

int		validelemet(char *stack1)
{
	int	i;

	i = 0;
	while (stack1[i])
	{
		if (stack1[i] == '-' && ft_isdigit(stack1[i + 1]))
			i++;
		if((stack1[i] >= 48 && stack1[i] <= 57) || stack1[i] == ' ')
			i++;
		else
			return(0);
	}
	return(1);
}
