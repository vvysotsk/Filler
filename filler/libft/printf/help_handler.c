/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 17:00:55 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 17:00:56 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_place_handle(t_data *data, char **str)
{
	if (data->place == -1)
		return ;
	if (ft_strlen(*str) <= (size_t)data->place)
		return ;
	(*str)[data->place] = '\0';
}

void		ft_build_new(t_data *data, char **str, char *new_str)
{
	char	c;

	c = 0;
	if (data->fl & 1 << 3)
	{
		c = (!ft_digit((*str)[0])) && data->ch == 'd' ? (*str)[0] : 0;
		ft_memset(new_str, '0', data->size - ft_strlen(*str) + !!c);
		if (c)
		{
			new_str[0] = c;
			(*str)[0] = '0';
		}
	}
	else
	{
		ft_memset(new_str, ' ', data->size - ft_strlen(*str));
		if ((data->fl & 1 << 1) && **str != '-')
			new_str[data->size - ft_strlen(*str)] = \
			((*str)[0] == '-') ? '-' : '+';
	}
	ft_strcpy(new_str + data->size - ft_strlen(*str) + !!c, *str + !!c);
}

void		ft_place_num(t_data *data, char **str)
{
	char	*new_str;
	char	*buff;
	char	c;

	buff = *str;
	if (data->place == 0 && !ft_strcmp("0", *str))
	{
		**str = '\0';
		return ;
	}
	if (data->place == -1)
		data->place = 1;
	if ((size_t)data->place < ft_strlen(*str))
		return ;
	c = (!ft_digit((*str)[0]) && data->ch == 'd') ? (*str)[0] : 0;
	if (c)
		(*str)++;
	new_str = ft_strnew(data->place + !!c);
	ft_memset(new_str + !!c, '0', data->place - ft_strlen(*str));
	ft_strcpy(new_str + data->place - ft_strlen(*str) + !!c, *str);
	if (c)
		new_str[0] = c;
	free(buff);
	*str = new_str;
}

void		ft_main_dividing(t_data *data, char **str)
{
	char	*new_str;

	if (data->size == 0 || ft_strlen(*str) >= (size_t)data->size)
		return ;
	new_str = ft_strnew(data->size);
	if (data->fl & 1 << 0)
	{
		ft_strcpy(new_str, *str);
		ft_memset(new_str + ft_strlen(*str), ' ', \
			data->size - ft_strlen(*str));
	}
	else
		ft_build_new(data, str, new_str);
	free(*str);
	*str = new_str;
	return ;
}
