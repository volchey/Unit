/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:38:22 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/07 17:38:30 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s0;
	size_t			i;

	s0 = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s0[i] == (unsigned char)c)
			return (&s0[i]);
		i++;
	}
	return (NULL);
}
