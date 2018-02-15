/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:26:57 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 12:36:23 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst0;
	unsigned char	*src0;
	size_t			i;

	dst0 = (unsigned char*)dst;
	src0 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst0[i] = src0[i];
		i++;
	}
	return (dst);
}
