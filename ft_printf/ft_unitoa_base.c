/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:26:03 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/31 15:26:05 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_base_str(unsigned int nb, int base, long len,
									t_list **str)
{
	char	chr[16] = "0123456789abcdef";

	if (nb == 0)
		ft_chrjoin(str, '0');
	while (len > 0)
	{
		ft_chrjoin(str, chr[nb / len]);
		nb %= len;
		len /= base;
	}
}

void		ft_unitoa_base(unsigned int nb, int base, t_list **str)
{
	long	len;

	len = 1;
	while (nb / len > (base - 1))
		len *= base;
	ft_base_str(nb, base, len, str);
}
