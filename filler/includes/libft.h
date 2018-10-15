/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:39:17 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/20 14:36:59 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "printf.h"
# define BUFF_SIZE 1
# define DESCRIPTOR_SIZE 9999
# define ENDL '\n'
# define END '\0'

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_descriptor
{
	char			*start;
	char			*current;
	char			*end;
	int				full_read;
}					t_descriptor;

char				**ft_save_str (char **ar_str, const char *str,
	char delimiter, int str_count);
int					ft_int_len(int n);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *str, const char *to_find);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find, int len);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *str, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_itoa(int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strcat(char *dest, const char *src);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *dest, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
int					ft_isprint(int ch);
int					ft_isdigit(int ch);
int					ft_isascii(int ch);
int					ft_isalpha(int ch);
int					ft_isalnum(int ch);
void				*ft_bzero(void *str, size_t n);
int					ft_atoi(const char *str);
int					ft_find_nword (const char *str, char delimiter, int index);
int					ft_count_str(const char *s, char delimiter);
int					ft_count_char(const char *str, int index, char delimiter);
size_t				ft_find_char(const char *s, int c);
void				*ft_realloc(void *ptr, size_t src_size, size_t new_size);
void				*ft_recalloc(void *ptr, size_t src_size, size_t new_size);
char				*ft_itoa_base(int value, int base);
char				*ft_imaxtoa(intmax_t value);
void				ft_save_to_str(char **s1, char *s2);
char				*ft_uimaxtoa_base(uintmax_t value, int8_t base, \
					const char *str);
int					get_next_line(const int fd, char **line);
char				*expand_pad(char c, int repeat, char *result, int *bsize);
void				*expand_write(void *new, int newlen, void *src, int *srcsize);
char				*ft_strnchr(const char *s, int c, size_t size);
#endif
