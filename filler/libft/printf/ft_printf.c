/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:55:24 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:55:25 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void			ft_printf_data(t_data *data)
{
	data->fl = 0;
	data->length = -1;
	data->ch = 'N';
	data->size = 0;
	data->place = -1;
	data->boool = 0;
}

int				ft_start_printf(char **m_str, const char *format, va_list ap)
{
	size_t		char_i;
	t_f_out		f_out;
	t_data		data;

	ft_printf_data(&data);
	if (ft_form_out(&f_out, ft_strlen(format) + 50) == -1)
		return (-1);
	while (*format)
	{
		char_i = 0;
		while (format[char_i] && format[char_i] != '%')
			char_i++;
		ft_set_form(&f_out, (char *)format, char_i);
		format += char_i;
		if (*format == '%')
		{
			if (*(++format) == 0)
				break ;
			ft_handle(&f_out, &format, &data, ap);
		}
		ft_printf_data(&data);
	}
	*m_str = ft_strndup(f_out.data, f_out.len);
	ft_form_free(&f_out);
	return (f_out.len);
}

int				ft_check_printf(char **m_str, const char *format, va_list ap)
{
	if (*format == '\0')
		*m_str = ft_strnew(0);
	if (!m_str || !format || !*format)
		return (0);
	if (ft_strchr(format, '%') == NULL)
	{
		if ((*m_str = ft_strdup(format)) == NULL)
			return (-1);
		return (ft_strlen(*m_str));
	}
	return (ft_start_printf(m_str, format, ap));
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	char	*m_str;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	len = ft_check_printf(&m_str, format, ap);
	write(1, m_str, len);
	free(m_str);
	va_end(ap);
	return (len);
}
