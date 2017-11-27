/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:23:30 by vfil              #+#    #+#             */
/*   Updated: 2017/11/27 15:40:44 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_var
{
	int			i;
	int			j;
	int			k;
	int			d;
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

void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_arriter(char **s, void (*f)(void *));
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_strdel(char **as);
char			*ft_read_file(char *name);
void			ft_start(t_tetrim *tt, int count_tt, int *sq_size);
int				ft_sqrt_mod(int count);
int				ft_check_nl(char *str);
int				ft_count_tetriminos(char *str);
char			**ft_check_all(char *str);
int				ft_check_end(char *str);
int				ft_check_nob(char	**tt_set);
int				ft_difference(int i, int j);
int				ft_check_neighbor(char *str);
char			**ft_parse_tt(char *s, int n_o_t);
t_tetrim		*ft_parse_coord(char **str, int count);
t_coord			ft_find_min_xy(t_tetrim *tt);
t_coord			ft_find_max_xy(t_tetrim *tt, int *sq_size);
void			ft_shift_x2start(t_tetrim *tt);
void			ft_shift_y2start(t_tetrim *tt);
int				ft_shift_tt(t_tetrim *tt, int *sq_size);
int				ft_check_char(t_tetrim *tt, int y, int x, int count);
void			ft_putarr(char **res);
void			ft_show(t_tetrim *tt, int count, int sq_size);
int				ft_verify(t_tetrim *tt, int i);
void			ft_fill(t_tetrim *tt, int *sq_size, int count);

#endif
