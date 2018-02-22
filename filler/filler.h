/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:30:04 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/15 16:30:06 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct		s_xy
{
	int				x;
	int				y;
	int				player;
}					t_xy;

typedef struct		s_row
{
	int				width;
	t_xy			*row;
}					t_row;

typedef struct 		s_map
{
	int				height;
	t_row			*map;
}					t_map;

t_map				ft_parse_map(char *buf);
t_xy				ft_get_coord(t_map map, t_map piece, int p);
int			 		ft_getplayer(char *line);
t_xy				ft_parse_piece(t_map map, int p, char *buf);
int					ft_set_position(t_map map, t_xy *psbl_xy, int p);

#endif
