/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:52:28 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/09 10:34:50 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(dst);
	if (i <= dstsize)
		k = i + ft_strlen(src);
	else
		k = dstsize + ft_strlen(src);
	while (dstsize && i < dstsize - 1)
	{
		if (*src)
			dst[i] = *src;
		else
			dst[i] = '\0';
		i++;
		src++;
	}
	dst[i] = '\0';
	return (k);
}
