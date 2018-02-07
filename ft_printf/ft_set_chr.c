/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:29:12 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/05 18:29:14 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_chr(char c, t_list **str, t_format *f)
{
	int		len;
	char	chr;

	len = 1;
	chr = ' ';
	if (f->width > len)
	{
		if (f->minus)
			ft_chrjoin(str, c);
		if (f->zero)
			chr = '0';
		while (len < f->width)
		{
			ft_chrjoin(str, chr);
			len++;
		}
		if (!f->minus)
			ft_chrjoin(str, c);
	}
	else
		ft_chrjoin(str, c);
}
