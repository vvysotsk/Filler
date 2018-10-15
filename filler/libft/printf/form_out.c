/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:45:49 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/02 18:45:50 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_form_new(t_f_out *f_out, size_t size)
{
	size_t	new_size;

	if (!(f_out->data))
		ft_form_out(f_out, size);
	new_size = f_out->space;
	while (new_size < size)
		new_size *= 2;
	f_out->data = (char *)ft_recalloc(f_out->data, f_out->len, new_size);
	f_out->space = new_size;
}

void		ft_set_form(t_f_out *f_out, char *data, size_t size)
{
	size_t	new_len;

	new_len = size;
	if (f_out->space < (f_out->len + new_len))
		ft_form_new(f_out, f_out->len + new_len);
	ft_memcpy(f_out->data + f_out->len, data, new_len);
	f_out->len += new_len;
}

void		ft_form_free(t_f_out *f_out)
{
	if (f_out->data && f_out->space > 0)
	{
		free(f_out->data);
		f_out->data = NULL;
	}
}

int			ft_form_out(t_f_out *f_out, size_t space)
{
	if (!f_out || !space)
		return (-1);
	f_out->len = 0;
	f_out->space = space;
	if ((f_out->data = ft_memalloc(sizeof(char) * f_out->space)) == NULL)
		return (-1);
	return (0);
}

void		ft_set_data(t_f_out *f_out, char *data)
{
	size_t	new_len;

	new_len = ft_strlen(data);
	if (f_out->space < (f_out->len + new_len))
		ft_form_new(f_out, f_out->len + new_len);
	ft_memcpy(f_out->data + f_out->len, data, new_len);
	f_out->len += new_len;
}
