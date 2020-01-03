/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 09:26:50 by kdeloise          #+#    #+#             */
/*   Updated: 2020/01/03 11:28:46 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	atoi_for_ps(const char *str)
{
	int					i;
	long				nbr;
	int					negative;

	i = 0;
	nbr = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	(str[i] == '-') ? negative *= -1 : negative;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	nbr = nbr * negative;
	if (nbr > 2147483647 || nbr < -2147483648)
	{
        ft_printf("error <more_then_int>\n");
		exit (1);
	}
	return ((int)nbr);
}
