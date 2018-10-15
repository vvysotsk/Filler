/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:14:39 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:50:05 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buff_dest;
	unsigned char	*buff_src;
	int				length;

	length = (int)n;
	buff_dest = (unsigned char *)dest;
	buff_src = (unsigned char *)src;
	if (buff_src < buff_dest)
	{
		while (--length > -1)
			buff_dest[length] = buff_src[length];
	}
	else
	{
		while (length--)
			*buff_dest++ = *buff_src++;
	}
	return (dest);
}
