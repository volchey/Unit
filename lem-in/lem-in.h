/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:35:24 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/10 14:35:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#include "libft.h"

typedef struct		s_room
{
	char			*name;
	int 			x;
	char			status;
	int 			y;
}					t_room;

typedef struct		s_link
{
	int 			room1;
	int 			room2;
}					t_link;

typedef struct 		s_way
{
	int 			room;
	struct s_way	*next;
}					t_way;

typedef struct 		s_ways
{
	t_way			*way;
	struct s_ways	*next;
}					t_ways;

t_list				*read_file();
t_room				*parse_rooms(t_list *list);
t_link				*parse_links(t_list *list, t_room *rooms);
t_ways				*get_ways(t_link *links, t_room *rooms);
void				ft_exit();
t_way				*new_node(int room);
t_way				*last_node(t_way *way);
void				arr_del(char **arr);

#endif
