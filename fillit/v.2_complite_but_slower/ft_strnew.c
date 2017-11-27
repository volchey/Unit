/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:00:29 by vfil              #+#    #+#             */
/*   Updated: 2017/11/24 16:27:07 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (size + 1));
	if (new != NULL)
		ft_bzero(new, size + 1);
	return (new);
}
