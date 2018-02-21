/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:37:16 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 12:37:57 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst0;
	unsigned char	*src0;
	size_t			i;

	dst0 = (unsigned char*)dst;
	src0 = (unsigned char*)src;
	i = 0;
	if (dst0 > src0)
		while (len)
		{
			dst0[len - 1] = src0[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			dst0[i] = src0[i];
			i++;
		}
	return (dst);
}
