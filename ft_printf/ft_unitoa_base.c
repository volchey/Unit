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

static void	ft_base_str(unsigned long long nb, int base, unsigned long long len,
									t_list **str)
{
	char	chr[17] = "0123456789abcdef";

	while (len > 0)
	{
		ft_chrjoin(str, chr[nb / len]);
		nb %= len;
		len /= base;
	}
}

void		ft_unitoa_base(unsigned long long nb, int base, t_list **str)
{
	unsigned long long	len;

	len = 1;
	while (nb / len > (unsigned  long long)(base - 1))
		len *= base;
	ft_base_str(nb, base, len, str);
}
