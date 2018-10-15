/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:01:20 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:01:22 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_place_wstr(t_data *data, wchar_t *wstr)
{
	size_t		j;
	size_t		index;

	index = 0;
	j = 0;
	if (data->place == -1)
		return ;
	if (ft_wlen(wstr) <= (size_t)data->place)
		return ;
	while (wstr[index] && j <= (size_t)data->place)
	{
		j += ft_bit_check(wstr[index]);
		index++;
	}
	wstr[index - 1] = '\0';
}

char			*ft_transform(wchar_t *wstr)
{
	char		*dest;
	size_t		index;
	size_t		atd;

	index = 0;
	atd = 0;
	dest = ft_strnew(ft_wlen(wstr));
	while (wstr[index])
	{
		ft_uni(wstr[index], dest + atd);
		atd += ft_bit_check(wstr[index]);
		index++;
	}
	return (dest);
}

void			ft_wstr(t_f_out *f_out, t_data *data, va_list ap)
{
	wchar_t		*tmp;
	char		*new_str;

	tmp = va_arg(ap, wchar_t *);
	if (!tmp)
		new_str = ft_put_null(data);
	else
	{
		tmp = ft_get_wstr(tmp);
		ft_place_wstr(data, tmp);
		new_str = ft_transform(tmp);
		free(tmp);
	}
	ft_main_dividing(data, &new_str);
	ft_set_data(f_out, new_str);
	free(new_str);
}

wchar_t			*ft_get_wstr(wchar_t *wstr)
{
	wchar_t		*new_wstr;
	size_t		length;

	length = 0;
	while (wstr[length])
		++length;
	new_wstr = (wchar_t *)malloc(sizeof(wchar_t) * (length + 1));
	if (!new_wstr)
		return (NULL);
	length = 0;
	while (wstr[length])
	{
		new_wstr[length] = wstr[length];
		length++;
	}
	new_wstr[length] = '\0';
	return (new_wstr);
}

size_t			ft_wlen(wchar_t *wstr)
{
	size_t		j;
	size_t		index;

	index = 0;
	j = 0;
	while (wstr[index])
	{
		j += ft_bit_check(wstr[index]);
		index++;
	}
	return (j);
}
