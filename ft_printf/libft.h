/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:37:25 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/11 16:51:10 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 60

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_format
{
	int				minus;
	int				plus;
	int				space;
	int				hesh;
	int				zero;
	int				width;
	int				precision;
	const char		*variable;
}					t_format;

void				ft_set_chr(char c, t_list **str, t_format *format);
int					ft_put_del_lst(t_list **head);
void				ft_unitoa_uppbase(unsigned long long nb, int base,
										t_list **str, t_format *format);
void				ft_set_str(char *s1, t_list **str, t_format *format);
void				ft_unitoa_base(unsigned long long nb, int base,
									t_list **str, t_format *format);
void				get_farg(va_list ap, t_format *format, t_list **str,
								int *length);
void				clear_struct(t_format *format);
void				ft_unistr(int *ptr, t_list **str, t_format *format);
void				ft_unichr(unsigned int value, t_list **str);
unsigned long long	ft_power(long long value, int power);
void				ft_get_address(unsigned long long n, t_list **str,
									t_format *format);
char				*ft_strcpy(char *dest, const char *src);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				ft_chrjoin(t_list **str, char c);
int					set_arg(t_list **str, va_list ap, t_format *format);
int					ft_printf(const char *restrict format, ...);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_itoa(long long n, t_list **str, t_format *format);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_isupper(int c);

#endif
