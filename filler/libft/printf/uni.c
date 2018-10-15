/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:58:40 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:58:42 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_get_wchar(char **raw, va_list ap)
{
	wchar_t	z;
	int		space;

	z = va_arg(ap, wchar_t);
	space = ft_bit_check(z);
	*raw = ft_strnew(space);
	ft_uni(z, *raw);
	return (z == '\0');
}

void		ft_ascii_zero(t_f_out *f_out, char *raw)
{
	int		index;
	int		j;

	index = 0;
	j = ft_strlen(raw);
	while (index < j)
	{
		if (raw[index] == 1)
			raw[index] = 0;
		index++;
	}
	ft_set_form(f_out, raw, j);
}

void		ft_char(t_f_out *f_out, t_data *data, va_list ap)
{
	char	c;
	char	*tmp;
	int		zero;

	zero = 0;
	if (data->ch == 'C' || data->length == l)
	{
		zero = ft_get_wchar(&tmp, ap);
		if (zero)
			tmp[0] = zero;
	}
	else
	{
		c = va_arg(ap, int);
		tmp = ft_strnew(1);
		zero = (c == '\0') ? 1 : 0;
		tmp[0] = c + zero;
	}
	ft_main_dividing(data, &tmp);
	if (zero)
		ft_ascii_zero(f_out, tmp);
	else
		ft_set_data(f_out, tmp);
	free(tmp);
}

void		ft_uni(wchar_t c, char *raw)
{
	if (c < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		raw[0] = (unsigned char)c;
	else if (c < (1 << 11))
	{
		raw[0] = (unsigned char)((c >> 6) | 0xC0);
		raw[1] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		raw[0] = (unsigned char)(((c >> 12)) | 0xE0);
		raw[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		raw[2] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		raw[0] = (unsigned char)(((c >> 18)) | 0xF0);
		raw[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		raw[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		raw[3] = (unsigned char)((c & 0x3F) | 0x80);
	}
}

int			ft_bit_check(wchar_t z)
{
	if (z < (1 << 7))
		return (1);
	else if (z < (1 << 11))
		return (2);
	else if (z < (1 << 16))
		return (3);
	else if (z < (1 << 21))
		return (4);
	return (0);
}
