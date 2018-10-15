/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:59:22 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:59:23 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_percent_conversion(t_f_out *f_out, t_data *data, va_list ap)
{
	char	*tmp;

	(void)ap;
	tmp = ft_strnew(1);
	*tmp = data->ch;
	ft_main_dividing(data, &tmp);
	ft_set_data(f_out, tmp);
	free(tmp);
}

void		ft_handle(t_f_out *f_out, const char **format, \
	t_data *data, va_list ap)
{
	if (**format == '{' && (ft_color(f_out, format) == true))
		return ;
	while (1)
	{
		if (set_flags(format, data))
			continue ;
		if (set_size(format, data, ap))
			continue ;
		if (set_place(format, data, ap))
			continue ;
		if (set_len(format, data))
			continue ;
		if (**format == '\0')
			return ;
		data->ch = *(*format)++;
		break ;
	}
	ft_conversion(f_out, data, ap);
}

t_conv_opt		g_conv_opt[] =
{
	{'d', &ft_num},
	{'D', &ft_num},
	{'i', &ft_num},
	{'p', &ft_hex},
	{'o', &ft_octal},
	{'O', &ft_octal},
	{'x', &ft_hex},
	{'X', &ft_hex},
	{'u', &ft_dec},
	{'U', &ft_dec},
	{'s', &ft_str},
	{'S', &ft_wstr},
	{'c', &ft_char},
	{'C', &ft_char},
	{'b', &ft_binary},
	{'f', &ft_float},
	{'n', &ft_none},
	{'%', &ft_percent_conversion}
};

void		ft_conversion(t_f_out *f_out, t_data *data, va_list ap)
{
	int		index;

	index = 0;
	while (index < 18)
	{
		if (data->ch == g_conv_opt[index].c)
		{
			g_conv_opt[index].f(f_out, data, ap);
			return ;
		}
		index++;
	}
	ft_percent_conversion(f_out, data, ap);
}
