/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:16:09 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/21 17:00:02 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_mod(int count)
{
	int	res;

	res = 2;
	while (res * res < count * 4)
		res++;
	return (res);
}
