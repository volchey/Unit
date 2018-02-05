/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:22 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/15 20:20:36 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_address(unsigned long nb, long len, t_list **str)
{
	char	chr[16] = "0123456789abcdef";

	while (len > 0)
	{
		ft_chrjoin(str, chr[nb / len]);
		nb %= len;
		len /= 16;
	}
}

void		ft_get_address(unsigned long nb, t_list **str)
{
	long	len;

	len = 1;
	ft_chrjoin(str, '0');
	ft_chrjoin(str, 'x');
	while (nb / len > 15)
		len *= 16;
	ft_set_address(nb, len, str);
}
