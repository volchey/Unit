/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:38:47 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:41:00 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	n;

	res = NULL;
	i = 0;
	j = 0;
	if (s)
	{
		n = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == n)
			return (ft_strnew(1));
		while (s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t')
			n--;
		if ((res = (char*)malloc(sizeof(char) * (n - i + 1))) == NULL)
			return (res);
		while (i < n)
			res[j++] = s[i++];
		res[j] = '\0';
	}
	return (res);
}
