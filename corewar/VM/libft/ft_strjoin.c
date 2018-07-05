/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:37:07 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:38:31 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*map;
	int		i;

	map = NULL;
	i = 0;
	if (s1 && s2)
	{
		if ((map = (char*)malloc(sizeof(char)
						* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			while (*s1)
			{
				map[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				map[i++] = *s2;
				s2++;
			}
			map[i] = '\0';
		}
	}
	return (map);
}
