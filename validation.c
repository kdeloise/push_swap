/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:08:37 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/03 17:47:24 by kdeloise         ###   ########.fr       */
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

void	check_double(char *str)
{
	int		*stack_a;
	int		*tmp;
	int		count;
	int		i;
	int     j;

	count = len_nbr(str);
	ft_printf("count - %d\n", count);
	stack_a = (int *)malloc(sizeof(int) * count);
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
			ft_printf("stack_a[%d] = %d\n", j, stack_a[j]);
			j++;
		}
		while(ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}
	tmp = stack_a;
	//bubble_sort_array(stack_a, count);
	quicksort(tmp, 0, count - 1);
	i = 0;
	j = 0;
	while(i < count - 1)
	{
		if (tmp[i] == tmp[i + 1])
		{
			ft_printf("error <double>\n");
			exit (1);
		}
		i++;
	}
	create_stack_a(stack_a, count);
}

void	validate_of_stack(char *str)
{
	int i;

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
	check_double(str);
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
