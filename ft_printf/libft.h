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

#define BUFF_SIZE 64

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
	int 			plus;
	int 			space;
	int 			hesh;
	int 			zero;
	int 			width;
	int 			precision;
	const char		*variable;
}					t_format;

void 				ft_set_chr(char c, t_list **str, t_format *format);
int					ft_put_del_lst(t_list **head);
void				ft_unitoa_uppbase(unsigned long long nb, int base,
									  t_list **str, t_format *format);
void				ft_set_str(char *s1, t_list **str, t_format *format);
void				ft_unitoa_base(unsigned long long nb, int base,
								   t_list **str, t_format *format);
void				get_farg(va_list ap, t_format *format, t_list **str,
							 int *length);
char                *ft_itoa_base(int nb, int base);
void				clear_struct(t_format *format);
void				ft_unistr(int *ptr, t_list **str, t_format *format);
void				ft_unichr(unsigned int value, t_list **str);
unsigned long long	ft_power(long long value, int power);
char				*ft_binary(int value);
void				ft_get_address(unsigned long long n, t_list **str,
								   t_format *format);
char        		*ft_oct_unlltoa(unsigned long long n);
char				*ft_oct_itoa(unsigned long n);
char				*ft_unitoa(unsigned int n);
char				*ft_hex_itoa(unsigned long int x);
char				*ft_upphex_itoa(unsigned long int x);
char				*ft_chr_to_str(char c);
void 				ft_chrjoin(t_list **str, char c);
int					set_arg(t_list **str, va_list ap, t_format *format);
int					ft_printf(const char *restrict format, ...);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_count_word(char const *s, char c);
void				ft_itoa(long long n, t_list **str, t_format *format);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_arriter(char **s, void (*f)(void *));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isupper(int c);
int					ft_islower(int c);
void				ft_strlwr(char *s);
void				ft_strupr(char *s);

#endif
