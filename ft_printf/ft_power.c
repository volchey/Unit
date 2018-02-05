/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:16:02 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/20 13:19:29 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_power(long long num, int power)
{
	int	res;

	res = num;
	if (power <= 0)
		res = 1;
	while (power > 1)
	{
		res *= num;
		power--;
	}
	return (res);
}
