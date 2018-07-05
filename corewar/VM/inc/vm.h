#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/libft.h"

int	atoi_base(char *str, int base);

typedef struct		s_bot
{
    unsigned char	name[PROG_NAME_LENGTH + 1];
    unsigned char	comment[COMMENT_LENGTH + 1];
    unsigned int	size;
    unsigned char	code[CHAMP_MAX_SIZE + 1];
    unsigned int	id;
}					t_bot;

t_bot				parse_bot(char *botName);
unsigned int		swap_4bits(unsigned char *buf);
short 				swap_2bits(unsigned char *buf);
void				ft_exit(char *);
void				print_map(unsigned char *map);

#endif