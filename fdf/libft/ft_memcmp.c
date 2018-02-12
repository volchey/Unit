/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:39:23 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 12:40:26 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*d1;
	const unsigned char	*d2;

	d1 = (const unsigned char*)s1;
	d2 = (const unsigned char*)s2;
	while (n--)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		else
		{
			d1++;
			d2++;
		}
	}
	return (0);
}
