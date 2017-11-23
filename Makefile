# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 10:16:29 by vfil              #+#    #+#              #
#    Updated: 2017/11/23 08:58:00 by vchechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ft_count_tetriminos.c
# -----------------------------------------------------------------------------
# =============================================================================
# ft_check_all.c
# -----------------------------------------------------------------------------
# char		**ft_check_all(char *str);
# int		ft_check_end(char *str);
# int		ft_check_nob(char **tt_set);
# int		ft_difference(int i, int j);
# int		ft_check_neighbor(char *str);
# =============================================================================
# ft_parse.c
# -----------------------------------------------------------------------------
# char		**ft_parse_tt(char *s, int n_o_t);
# t_tetrim	*ft_parse_coord(char **str, int count);
# =============================================================================
# ft_shift_tt.c
# -----------------------------------------------------------------------------
# t_coord	ft_find_minxy(t_tetrim *tt);
# t_coord	ft_find_max_xy(t_tetrim *tt, int *sq_size);
# void		ft_shift_x2start(t_tetrim *tt);
# void		ft_shift_y2start(t_tetrim *tt);
# int		ft_shift_tt(t_tetrim *tt, int *sq_size);
# =============================================================================
# ft_show.c
# -----------------------------------------------------------------------------
# int		ft_check_char(t_tetrim *tt, int y, int x, int count);
# void		ft_putarr(char **res);
# void		ft_show(t_tetrim *tt, int count, int sq_size);
#

NAME	=	fillit

LIB		=	libfill.a

MAIN	=	main.c

SRC		=	ft_count_tetriminos.c ft_check_all.c ft_parse.c \
			ft_shift_tt.c ft_show.c ft_fill.c ft_read_file.c

LSRC	=	ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c \
			ft_strcpy.c ft_strnew.c ft_strsub.c ft_bzero.c ft_arriter.c

LOSRC	=	$(LSRC:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OSRC)
	@gcc $(FLAGS) -c $(LSRC)
	@ar rc $(LIB) $(LOSRC)
	@gcc $(FLAGS) $(MAIN) $(SRC) -L. -lfill -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
