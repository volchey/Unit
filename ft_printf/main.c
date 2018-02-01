/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:37:36 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/11 17:50:47 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <locale.h>

int main()
{
	char	*str;
//	int		x[4] = {945, 256, 23, 0};

	setlocale(LC_ALL, "");
	str = ft_strnew(2);
	str[0] = 'H';
//    ft_putstr(ft_itoa(0));
//    ft_putchar('\n');
	ft_printf("ft_printf:  %X %o %u %10d %s %p %C\n", 42, -123, -123, -123, "-123", str, 345768);
	printf("ft_printf:  %X %o %u %d %s %p %C\n", 42, -123, -123, -123, "-123", str, 345768);
	free(str);
//	system("leaks a.out");
}
