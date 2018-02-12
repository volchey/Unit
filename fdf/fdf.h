/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:05:22 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/09 16:05:24 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "libft/libft.h"
#include <fcntl.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_row
{
	int 		size;
	t_coord		*coord;
}				t_row;

typedef	struct	s_arae
{
	int 		gx;
	int 		gy;
	int 		vx;
	int 		vy;
	int			h;
}				t_area;

typedef struct	s_mlx
{
	char 		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	t_coord		st_xy;
	t_area		area;
}				t_mlx;

t_row			*parse_map(char *line, t_coord st_xy, t_area area);
void			draw_line(t_coord st_xy, t_coord end_xy, void *mlx_ptr,
							void *win_ptr);
void			draw_map(t_row *map, void *mlx_ptr, void *win_ptr);

#endif
