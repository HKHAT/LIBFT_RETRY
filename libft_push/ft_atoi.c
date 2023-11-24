/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:33 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/19 20:23:23 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	nbr;
	int					sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr = (nbr * 10) + str[i++] - 48;
		if (nbr >= LLONG_MAX && sign == 1)
			return (-1);
		else if (nbr >= LLONG_MAX && sign == -1)
			return (0);
	}
	return ((int)(nbr * sign));
}
