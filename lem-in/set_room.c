/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:28:57 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/29 18:29:00 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	set_room(char *str, char status)
{
	t_room	room;
	char	**arr;

	room.status = status;
	arr = ft_strsplit(str, ' ');
	room.name = ft_strdup(arr[0]);
	room.x = ft_atoi(arr[1]);
	room.y = ft_atoi(arr[2]);
	ft_strdel(&arr[0]);
	ft_strdel(&arr[1]);
	ft_strdel(&arr[2]);
	free(arr);
	return (room);
}
