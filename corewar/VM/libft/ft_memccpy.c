/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:28:59 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 12:35:30 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst0;
	unsigned char	*src0;

	dst0 = (unsigned char*)dst;
	src0 = (unsigned char*)src;
	while (n--)
	{
		*dst0 = *src0;
		if (*src0 == (unsigned char)c)
			return (++dst0);
		dst0++;
		src0++;
	}
	return (NULL);
}
