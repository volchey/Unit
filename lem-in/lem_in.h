/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:35:24 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/10 14:35:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_coord
{
	float			x;
	float			y;
}					t_coord;

typedef struct		s_file
{
	char			*content;
	struct s_file	*next;
}					t_file;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				color;
}					t_mlx;

typedef struct		s_room
{
	char			*name;
	int				x;
	char			status;
	int				y;
}					t_room;

typedef struct		s_link
{
	int				room1;
	int				room2;
}					t_link;

typedef struct		s_way
{
	int				room;
	struct s_way	*next;
}					t_way;

typedef struct		s_ways
{
	t_way			*way;
	struct s_ways	*next;
}					t_ways;

typedef struct		s_ant
{
	int				ant;
	int				room;
}					t_ant;

t_file				*read_file();
t_room				*parse_rooms(t_file *list);
t_link				*parse_links(t_file *list, t_room *rooms);
t_ways				*get_ways(t_link *links, t_room *rooms);
void				ft_exit(char *str);
t_way				*new_node(int room);
t_way				*last_node(t_way *way);
void				arr_del(char **arr);
t_ways				*check_ways(t_ways *list, t_room *rooms);
t_ways				*del_way(t_ways *way, t_ways *list, t_ways **head);
void				lets_go(t_ant **ways, int count, t_room *rooms);
void				draw_farm(t_room *rooms, t_ant **ways, t_link *links);
void				draw_line(t_coord st_xy, t_coord end_xy, t_mlx c);
t_room				set_room(char *str, char status);
int					escape(int key);
void				put_ways(t_ways *ways, t_room *rooms);

#endif
