/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:33:50 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 16:04:02 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = NULL;
	i = 0;
	if (s && s[start] && (res = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len && s[start])
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = '\0';
	}
	return (res);
}
