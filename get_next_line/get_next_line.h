/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:43:48 by vchechai          #+#    #+#             */
/*   Updated: 2017/12/05 19:58:57 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 100000

typedef struct		s_file
{
	char			*str;
//	int				fd;
//	struct s_list	*next;
}					t_file;

int						get_next_line(const int fd, char **line);

#endif
