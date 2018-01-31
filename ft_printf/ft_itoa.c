/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:41:47 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 16:01:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_to_str(long int bn, long int i, int f, t_list **str)
{
	if (f)
		ft_chrjoin(str, '-');
	while (i > 0)
	{
		ft_chrjoin(str, (bn / i + '0'));
		bn %= i;
		i /= 10;
	}
}

void			ft_itoa(int n, t_list **str)
{
	long int	bn;
	long int	i;
	int			f;

	bn = n;
	i = 1;
	f = 0;
	if (bn < 0)
	{
		f = 1;
		bn *= -1;
	}
	while (bn / i > 9)
		i *= 10;
	ft_to_str(bn, i, f, str);
}

