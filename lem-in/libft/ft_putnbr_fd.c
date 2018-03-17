/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:56:07 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:57:12 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	i;

	nb = n;
	i = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	while (nb / i > 9)
		i *= 10;
	while (i > 0)
	{
		ft_putchar_fd(nb / i + '0', fd);
		nb %= i;
		i /= 10;
	}
}
