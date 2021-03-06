/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:20:26 by vfil              #+#    #+#             */
/*   Updated: 2017/11/09 16:47:56 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) ||
			(c >= 97 && c <= 122)) ? 1 : 0;
}
