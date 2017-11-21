/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:23:30 by vfil              #+#    #+#             */
/*   Updated: 2017/11/18 17:08:29 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_var
{
	int			i;
	int 		j;
	int			k;
	int 		d;
}				t_var;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetrim
{
	t_coord		block[4];
}				t_tetrim;

int				ft_count_tetriminos(char *str);
char			*ft_read_file(char *name);
char			**ft_parse_tt(char *s, int n_o_t);
void			ft_test_parse_tt(char **tt_set);
char			**ft_check_all(char *);
int				ft_check_neighbor(char *str);
char			**ft_convert_tt(char **tt_set);
int				ft_check_nob(char	**tt_set);
int				ft_check_end(char *str);
t_tetrim		*ft_parse_coord(char **str, int count);
void			coord_print(t_tetrim *arr, int count);
void			ft_shift_x2start(t_tetrim *tt);
void			ft_shift_y2start(t_tetrim *tt);
t_coord			ft_find_max_xy(t_tetrim *tt);
int				ft_shift_tt(t_tetrim *tt, int sq_size);
t_coord			ft_find_minxy(t_tetrim *tt);
int				ft_sqrt_mod(int count);
void			ft_show(t_tetrim *tt, int count, int sq_size);
int				ft_verify(t_tetrim *tt, int i, int sq_size, int count_tt);
void			ft_fill(t_tetrim *tt, int count, int sq_size);
void			ft_start(t_tetrim *tt, int count_tt, int sq_size);

#endif
