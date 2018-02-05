/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:55:19 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/05 15:55:22 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_str(char *s1, t_list **str, t_format *f)
{
	int	i;

	i = 0;
	if (f->space && !f->minus)
		ft_chrjoin(str, ' ');
	while (s1[i])
	{
		ft_chrjoin(str, s1[i]);
		i++;
		if (f->precision && i == f->precision)
			break ;
	}
}

void	ft_set_str(char *s1, t_list **str, t_format *f)
{
	int		len;
	char 	ptr[67] = "(null)";

	if (!s1)
		s1 = ptr;
	len = ft_strlen(s1);
	if(f->precision && f->precision != -1 && len > f->precision)
		len = f->precision;
	if(f->width > len)
	{
		if(f->minus)
			put_str(s1, str, f);
		while(len < f->width)
		{
			ft_chrjoin(str, ' ');
			len++;
		}
		if(!f->minus)
			put_str(s1, str, f);
	} else
		put_str(s1, str, f);
}
