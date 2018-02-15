/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:07:10 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/07 16:53:38 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int k;

	i = 0;
	while (haystack[i])
	{
		k = i;
		j = 0;
		while (haystack[k] == needle[j] && needle[j])
		{
			k++;
			j++;
		}
		if (!needle[j])
			return ((char*)&haystack[k - j]);
		i++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	return (NULL);
}
