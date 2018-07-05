/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:27:07 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:28:27 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	i = 0;
	map = NULL;
	if (s && f)
	{
		map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (map == NULL)
			return (NULL);
		while (s[i])
		{
			map[i] = f(s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
