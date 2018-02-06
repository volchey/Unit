/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:09:30 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:11:39 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	b1;
	unsigned char	b2;
	int				i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	b1 = s1[i];
	b2 = s2[i];
	return (b1 - b2);
}
