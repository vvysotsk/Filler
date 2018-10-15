/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:56:14 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 16:56:15 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_put_null(t_data *data)
{
	char	*str;

	if (data->place >= 1 || data->place == -1)
	{
		str = ft_strdup("(null)");
		if (data->place > 6)
			str[6] = '\0';
		else
			str[(data->place == -1) ? 6 : data->place] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}

void		ft_str(t_f_out *f_out, t_data *data, va_list ap)
{
	char	*tmp;
	char	*new_str;

	if (data->length == l)
	{
		ft_wstr(f_out, data, ap);
		return ;
	}
	tmp = va_arg(ap, char *);
	if (!tmp)
		new_str = ft_put_null(data);
	else
		new_str = ft_strdup(tmp);
	ft_place_handle(data, &new_str);
	ft_main_dividing(data, &new_str);
	ft_set_data(f_out, new_str);
	free(new_str);
}
