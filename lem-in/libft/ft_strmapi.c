/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:28:39 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:29:47 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	map = NULL;
	i = 0;
	if (s)
	{
		map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (map == NULL)
			return (map);
		while (s[i])
		{
			map[i] = f(i, s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
