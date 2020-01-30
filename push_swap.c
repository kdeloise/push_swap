/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:12:46 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/03 11:48:04 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		len_nbr(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while(str[i])
	{
		while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || \
				(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
			i++;
		if(str[i] != '\0')
			count++;
		while(str[i] && ((str[i] != '\n') && (str[i] != '\t') && (str[i] != '\v') && \
				(str[i] != ' ') && (str[i] != '\f') && (str[i] != '\r')))
			i++;
	}
	return (count);
}

int 	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*space;
	t_fl    fl;

	i = 1;
	while(argv[i])
	{
		if(!(validelemet(argv[i])))
		{
			if(str)
			{
				free(str);
				str = NULL;
			}
			ft_printf("%s\n", "error");
			return (0);
		}
		else
		{
			if (!str)
			{
				str = "";
				space = "";
			}
			else
				space = " ";
			str = ft_strjoin(ft_strjoin(str, space), argv[i]);
		}
		i++;
	}
	if(str)
	{
		fl = validate_of_stack(str);
//		ft_printf("%s\n", str);
//		ft_printf("\ncount = %d--\n", fl.count);
//		ft_printf("\n-----------\nit's data of stack_b\n-----------\n");
//		print_stack(fl.b);
//		ft_printf("\n-----------\nit's data of stack_a\n-----------\n");
//        print_stack(fl.a);
		push_swap_sort(&fl);
//		ft_printf("\n-----------\nit's data of stack_a<com>\n-----------\n");
//		print_stack(fl.a);
//		ft_printf("\n-----------\nit's data of stack_b<com>\n-----------\n");
//		print_stack(fl.b);
	}
	else
		ft_printf("don't have stack\n");
	ft_printf("valid stack\n");
	return(0);
}
