/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:00:04 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:00:05 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_num(t_f_out *f_out, t_data *data, va_list ap)
{
	intmax_t	num;
	char		*buff;

	if (data->ch == 'D')
		data->length = l;
	if (data->ch == 'i' || data->ch == 'D')
		data->ch = 'd';
	num = ft_set_int_len(data->length, ap);
	buff = ft_imaxtoa(num);
	if (data->place != -1 && data->fl & 1 << 3)
		data->fl ^= 1 << 3;
	if (data->place == 0 && !ft_strcmp("0", buff))
		*buff = '\0';
	if (((data->fl & 1 << 1 || data->fl & 1 << 2) && buff[0] != '-') \
		&& data->ch == 'd')
	{
		ft_save_to_str(&buff, (data->fl & 1 << 2) ? " " : "+");
		buff[0] = ((data->fl & 1 << 1)) ? '+' : buff[0];
	}
	ft_place_num(data, &buff);
	ft_main_dividing(data, &buff);
	ft_set_data(f_out, buff);
	free(buff);
}

void			ft_hex(t_f_out *f_out, t_data *data, va_list ap)
{
	uintmax_t	num;
	char		*buff;

	if (data->ch == 'p')
		data->length = j;
	num = ft_num_len(data->length, ap);
	buff = ft_uimaxtoa_base(num, 16, "0123456789abcdef");
	if (data->ch == 'p' && data->fl & 1 << 3 && data->boool)
		data->fl ^= 1 << 3;
	ft_num_handle(&buff, data);
	ft_set_data(f_out, buff);
	free(buff);
}

void			ft_octal(t_f_out *f_out, t_data *data, va_list ap)
{
	uintmax_t	num;
	char		*str;

	if (data->ch == 'O')
		data->length = l;
	num = ft_num_len(data->length, ap);
	str = ft_uimaxtoa_base(num, 8, "01234567");
	ft_num_handle(&str, data);
	ft_set_data(f_out, str);
	free(str);
}

void			ft_dec(t_f_out *f_out, t_data *data, va_list ap)
{
	uintmax_t	num;
	char		*str;

	if (data->ch == 'U')
		data->length = l;
	num = ft_num_len(data->length, ap);
	str = ft_uimaxtoa_base(num, 10, "0123456789");
	ft_num_handle(&str, data);
	ft_set_data(f_out, str);
	free(str);
}

intmax_t		ft_set_int_len(char length, va_list ap)
{
	if (length == hh)
		return ((signed char)va_arg(ap, int));
	if (length == h)
		return ((short)va_arg(ap, int));
	if (length == l)
		return (va_arg(ap, long));
	if (length == ll)
		return (va_arg(ap, long long));
	if (length == j)
		return (va_arg(ap, intmax_t));
	if (length == z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}
