/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:58:58 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/04 15:58:59 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_get_bit(t_data *data, char **str)
{
	char		*new_str;

	if (!(ft_x_or_0(data->ch) || data->ch == 'p' || data->ch == 'b'))
		return ;
	new_str = ft_strdup(*str);
	if (data->ch == 'p')
		ft_save_to_str(&new_str, "0x");
	else if (data->fl & 1 << 4)
	{
		if (data->ch == 'b' && ft_strcmp("0", *str) \
			&& ft_strcmp("\0", *str))
			ft_save_to_str(&new_str, "0b");
		else if (ft_isx(data->ch) && ft_strcmp("0", *str) \
			&& ft_strcmp("\0", *str))
			ft_save_to_str(&new_str, "0x");
		else if (ft_is0(data->ch) && **str != '0')
			ft_save_to_str(&new_str, "0");
	}
	free(*str);
	*str = new_str;
}

void			ft_num_handle(char **str, t_data *data)
{
	if (data->fl & 1 << 3 && data->place == 0)
		data->fl ^= 1 << 3;
	if (data->place == 0 && !ft_strcmp(*str, "0"))
		**str = '\0';
	ft_place_num(data, str);
	if (data->fl & 1 << 3 && data->ch == 'p')
	{
		data->size = ft_intcmp(data->size - 2, 0);
		ft_main_dividing(data, str);
	}
	else if (data->fl & 1 << 3 && data->fl & 1 << 4 && \
		(ft_isx(data->ch) || data->ch == 'b'))
	{
		data->size = ft_intcmp(data->size - 2, 0);
		ft_main_dividing(data, str);
	}
	ft_get_bit(data, str);
	if (!(data->fl & 1 << 3 && data->fl & 1 << 4 && (ft_isx(data->ch) \
		|| data->ch == 'p' || data->ch == 'b')))
		ft_main_dividing(data, str);
	ft_big_x(*str, data->ch);
}

uintmax_t		ft_num_len(char length, va_list ap)
{
	if (length == hh)
		return ((unsigned char)va_arg(ap, int));
	if (length == h)
		return ((unsigned short)va_arg(ap, int));
	if (length == l)
		return (va_arg(ap, unsigned long));
	if (length == ll)
		return (va_arg(ap, unsigned long long));
	if (length == j)
		return (va_arg(ap, uintmax_t));
	if (length == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

void			ft_big_x(char *str, char ch)
{
	if (ch != 'X')
		return ;
	while (*str)
	{
		if (ft_alpha(*str))
			*str = ft_up(*str);
		str++;
	}
}
