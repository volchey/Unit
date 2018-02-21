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

#include "libft/libft.h"

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

t_map				ft_parse_map(int fd);
t_xy				ft_get_coord(t_map map, t_map piece);
int			 		ft_getplayer(int fd);
t_map				ft_parse_piece(int fd, int p);


#endif
