/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:12:16 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:14:11 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	unsigned long int	res;
	int					f;
	int					i;

	res = 0;
	f = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
		f = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 7)) && f == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
						&& (str[i] - '0') > 8)) && f == -1)
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(res * f));
}
