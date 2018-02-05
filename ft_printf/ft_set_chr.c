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

	len = 1;
	if(f->width > len)
	{
		if(f->minus)
			ft_chrjoin(str, c);
		while(len < f->width)
		{
			ft_chrjoin(str, ' ');
			len++;
		}
		if(!f->minus)
			ft_chrjoin(str, c);
	} else
		ft_chrjoin(str, c);
}
