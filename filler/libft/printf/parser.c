/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:59:08 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:59:09 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_bool			set_len(const char **format, t_data *data)
{
	const char	len[] = "hhlljz";
	int			index;

	index = 0;
	if (ft_islen(**format))
	{
		index = ft_find_char(len, **format);
		if (index == 0)
		{
			if (*(*format + 1) == 'h')
				++*format;
			else
				index = 1;
		}
		if (index == 2)
			index = (*(*format + 1) == 'l') ? 3 : 2;
		data->length = ft_intcmp(index, data->length);
		++*format;
		return (true);
	}
	return (false);
}

t_bool			set_flags(const char **format, t_data *data)
{
	const char	fl[] = "-+ 0#";
	size_t		index;

	index = 0;
	while (fl[index] != **format && fl[index])
		index++;
	if (fl[index])
	{
		data->fl |= (1 << index);
		(*format)++;
		return (true);
	}
	return (false);
}

t_bool			set_place(const char **format, t_data *data, va_list ap)
{
	int			new_place;

	new_place = 0;
	if (**format != '.')
		return (false);
	data->boool = 1;
	(*format)++;
	if (**format == '*')
	{
		data->place = va_arg(ap, int);
		if (data->place < -1)
			data->place = -1;
		(*format)++;
		return (true);
	}
	while (ft_digit(**format))
	{
		new_place = new_place * 10 + (**format - '0');
		(*format)++;
	}
	data->place = new_place;
	return (true);
}

t_bool			set_size(const char **format, t_data *data, va_list ap)
{
	int			size;

	size = 0;
	if (**format == '*')
	{
		data->size = va_arg(ap, int);
		if (data->size < 0)
		{
			if (!(data->fl & 1 << 0))
				data->fl ^= 1 << 0;
			data->size *= -1;
		}
		(*format)++;
		return (true);
	}
	if (!ft_digit(**format))
		return (false);
	while (ft_digit(**format))
	{
		size = size * 10 + (**format - '0');
		(*format)++;
	}
	data->size = size;
	return (true);
}
