/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:07:49 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:45:12 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*buff_dest;
	unsigned const char	*buff_str;
	unsigned char		ch;

	buff_dest = (unsigned char *)dest;
	buff_str = (unsigned const char *)src;
	ch = (unsigned char)c;
	while (n--)
		if ((*buff_dest++ = *buff_str++) == ch)
			return ((void *)buff_dest);
	return (NULL);
}
