/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:08:30 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:08:31 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_f_out
{
	size_t		len;
	size_t		space;
	char		*data;
}				t_f_out;

typedef enum	e_islen
{
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_islen;

typedef struct	s_data
{
	char		fl;
	char		length;
	char		ch;
	int			size;
	int			place;
	int			boool:1;
}				t_data;

typedef struct	s_conv_opt
{
	char c;
	void (*f)(t_f_out *, t_data *, va_list);
}				t_conv_opt;

int				ft_printf(const char *format, ...);
int				ft_check_printf(char **m_str, const char *format, va_list ap);
int				ft_start_printf(char **m_str, const char *format, va_list ap);
int				ft_dprintf(int fd, const char *format, ...);
void			ft_handle(t_f_out *f_out, const char **format, \
				t_data *data, va_list ap);
void			ft_conversion(t_f_out *f_out, t_data *data, va_list ap);
void			ft_percent_conversion(t_f_out *f_out, t_data *data, va_list ap);
void			ft_main_dividing(t_data *data, char **str);
void			ft_build_new(t_data *data, char **str, char *new_str);
void			ft_place_handle(t_data *data, char **str);
void			ft_place_num(t_data *data, char **str);
int				ft_form_out(t_f_out *f_out, size_t space);
void			ft_form_new(t_f_out *f_out, size_t size);
void			ft_set_form(t_f_out *f_out, char *data, size_t size);
void			ft_set_data(t_f_out *f_out, char *data);
void			ft_form_free(t_f_out *f_out);
t_bool			set_size(const char **format, t_data *data, va_list ap);
t_bool			set_place(const char **format, t_data *data, va_list ap);
t_bool			set_flags(const char **format, t_data *data);
t_bool			set_len(const char **format, t_data *data);
intmax_t		ft_set_int_len(char length, va_list ap);
void			ft_num(t_f_out *f_out, t_data *data, va_list ap);
void			ft_hex(t_f_out *f_out, t_data *data, va_list ap);
void			ft_octal(t_f_out *f_out, t_data *data, va_list ap);
void			ft_dec(t_f_out *f_out, t_data *data, va_list ap);
uintmax_t		ft_num_len(char length, va_list ap);
void			ft_get_bit(t_data *data, char **str);
void			ft_big_x(char *str, char ch);
void			ft_num_handle(char **str, t_data *data);
wchar_t			*ft_get_wstr(wchar_t *wstr);
size_t			ft_wlen(wchar_t *wstr);
void			ft_place_wstr(t_data *data, wchar_t *wstr);
char			*ft_transform(wchar_t *wstr);
void			ft_wstr(t_f_out *f_out, t_data *data, va_list ap);
char			*ft_put_null(t_data *data);
void			ft_str(t_f_out *f_out, t_data *data, va_list ap);
void			ft_uni(wchar_t c, char *raw);
int				ft_bit_check(wchar_t z);
int				ft_get_wchar(char **raw, va_list ap);
void			ft_ascii_zero(t_f_out *f_out, char *raw);
void			ft_char(t_f_out *f_out, t_data *data, va_list ap);
void			ft_float(t_f_out *f_out, t_data *data, va_list ap);
void			ft_binary(t_f_out *f_out, t_data *data, va_list ap);
intmax_t		*ft_number_len(t_data *data, va_list ap);
void			ft_none(t_f_out *f_out, t_data *data, va_list ap);
t_bool			ft_color(t_f_out *f_out, const char **format);
int				ft_alpha(int ch);
int				ft_digit(int ch);
int				ft_isx(int c);
int				ft_is0(int c);
int				ft_x_or_0(int c);
int				ft_islen(int ch);
int				ft_intcmp(int x, int y);
int				ft_up(int ch);
#endif
