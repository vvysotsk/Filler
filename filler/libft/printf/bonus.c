/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:00:19 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:00:20 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_none(t_f_out *f_out, t_data *data, va_list ap)
{
	intmax_t	*ar;
	int			tmp;

	tmp = f_out->len;
	ar = ft_number_len(data, ap);
	*ar = (intmax_t)tmp;
}

char			g_color[33][2][15] = {
	{"{red}", "\033[31m"},
	{"{bred}", "\033[31;1m"},
	{"{green}", "\033[32m"},
	{"{bgreen}", "\033[32;1m"},
	{"{yellow}", "\033[33m"},
	{"{byellow}", "\033[33;1m"},
	{"{blue}", "\033[34m"},
	{"{bblue}", "\033[34;1m"},
	{"{purple}", "\033[35m"},
	{"{bpurple}", "\033[35;1m"},
	{"{cyan}", "\033[36m"},
	{"{bcyan}", "\033[36;1m"},
	{"{black}", "\033[30m"},
	{"{bblack}", "\033[30;1m"},
	{"{white}", "\033[37m"},
	{"{bwhite}", "\033[37;1m"},
	{"{b_red}", "\033[41m"},
	{"{b_bred}", "\033[41;1m"},
	{"{b_green}", "\033[42m"},
	{"{b_bgreen}", "\033[42;1m"},
	{"{b_yellow}", "\033[43m"},
	{"{b_byellow}", "\033[43;1m"},
	{"{b_blue}", "\033[44m"},
	{"{b_bblue}", "\033[44;1m"},
	{"{b_purple}", "\033[45m"},
	{"{b_bpurple}", "\033[45;1m"},
	{"{b_cyan}", "\033[46m"},
	{"{b_bcyan}", "\033[46;1m"},
	{"{b_black}", "\033[40m"},
	{"{b_bblack}", "\033[40;1m"},
	{"{b_white}", "\033[47m"},
	{"{b_bwhite}", "\033[47;1m"},
	{"{eoc}", "\033[0m"}
};

void			ft_float(t_f_out *f_out, t_data *data, va_list ap)
{
	(void)f_out;
	(void)data;
	(void)ap;
}

t_bool			ft_color(t_f_out *f_out, const char **format)
{
	int			index;

	index = 0;
	while (index < 33)
	{
		if (ft_strnstr(*format, g_color[index][0], \
			ft_strlen(g_color[index][0])) != 0)
		{
			ft_set_data(f_out, g_color[index][0]);
			*format = *format + ft_strlen(g_color[index][0]);
			return (true);
		}
		index++;
	}
	return (false);
}

void			ft_binary(t_f_out *f_out, t_data *data, va_list ap)
{
	uintmax_t	num;
	char		*new_str;

	num = va_arg(ap, unsigned long long);
	new_str = ft_uimaxtoa_base(num, 2, "01");
	ft_num_handle(&new_str, data);
	ft_set_data(f_out, new_str);
	free(new_str);
}

intmax_t		*ft_number_len(t_data *data, va_list ap)
{
	if (data->length == hh)
		return ((intmax_t *)va_arg(ap, signed char *));
	if (data->length == h)
		return ((intmax_t *)va_arg(ap, short *));
	if (data->length == l)
		return ((intmax_t *)va_arg(ap, long *));
	if (data->length == ll)
		return ((intmax_t *)va_arg(ap, long long *));
	if (data->length == j)
		return ((intmax_t *)va_arg(ap, intmax_t *));
	if (data->length == z)
		return ((intmax_t *)va_arg(ap, ssize_t *));
	return ((intmax_t *)va_arg(ap, int *));
}
