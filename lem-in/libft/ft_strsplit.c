/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:41:11 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/09 10:41:02 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w;
	int		start;
	char	**str;

	if (!s)
		return (0);
	i = 0;
	w = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[w++] = ft_strsub(s, start, (i - start));
	}
	str[w] = 0;
	return (str);
}
