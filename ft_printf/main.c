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

int main()
{
	char	*str;

	str = ft_strnew(2);
	str[0] = 'H';
	ft_printf("Hello: %d %cs %s %p %u\n", 5, 'i', "incredible", str, 4000000000);
//	printf("Hello: %d %cs %s %p %u", 5, 'i', "incredible", str, 400000000);
//	system("leaks a.out");
}
