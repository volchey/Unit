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

unsigned long long	ft_power(long long num, int power)
{
	unsigned long long	res;

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
