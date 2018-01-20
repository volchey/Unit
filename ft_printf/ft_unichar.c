/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unichar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:49:28 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:51:35 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_2_bytes(unsigned int value, unsigned char **octet)
{
	unsigned int	mask1;

	mask1 = 49280;
	(*octet)[0] = (((value >> 6) << 27) >> 27) | (mask1 >> 8);
	(*octet)[1] = ((value << 26) >> 26) | ((mask1 << 24) >> 24);	
}

static void set_3_bytes(unsigned int value, unsigned char **octet)
{
	unsigned int	mask2;

	mask2 = 14712960;
	(*octet)[0] = (((value >> 12) << 28) >> 28) | (mask2 >> 16);
	(*octet)[1] = (((value >> 6) << 26) >> 26) | ((mask2 << 16) >> 24);
	(*octet)[2] = ((value << 26) >> 26) | ((mask2 << 24) >> 24);
}

static void set_4_bytes(unsigned int value, unsigned char **octet)
{
	unsigned int	mask3;

	mask3 = 4034953344;
	(*octet)[0] = (((value >> 18) << 29) >> 29) | (mask3 >> 24);
	(*octet)[1] = ((value >> 12) << 26) >> 26 | ((mask3 << 8) >> 24);
	(*octet)[2] = ((value >> 6) << 26) >> 26 | ((mask3 << 16) >> 24);
	(*octet)[3] = ((value << 26) >> 26) | ((mask3 << 24) >> 24);
}

unsigned char	*ft_unichar(unsigned int value)
{
	int				size;
	unsigned char	*octet;
	char			*bin;

	bin = ft_binary(value);
	size = ft_strlen(bin);
	octet = (unsigned char*)malloc(sizeof(char) * (size + 1));
	ft_strdel(&bin);
	if (size < 8)
		octet[0] = value;
	else if (size < 12)
		set_2_bytes(value, &octet);
	else if (size < 17)
		set_3_bytes(value, &octet);
	else
		set_4_bytes(value, &octet);
	octet[size] = '\0';
	return (octet);
}
