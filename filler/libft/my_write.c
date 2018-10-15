/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:37:23 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:37:24 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*expand_write(void *new, int newlen, void *src, int *srcsize)
{
	int				length;
	int				newlength;
	char			*newbuf;

	length = newlen;
	newlength = *srcsize + length;
	newbuf = (char*)malloc(newlength);
	ft_memcpy(newbuf, src, *srcsize);
	ft_memcpy(newbuf + *srcsize, new, newlen);
	*srcsize = newlength;
	if (src)
		free(src);
	return (newbuf);
}
