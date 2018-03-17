/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:08:37 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/07 16:55:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && needle[j] && k < len)
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[k - j]);
		i++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	return (NULL);
}
