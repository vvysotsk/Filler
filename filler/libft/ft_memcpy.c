/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:27:24 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:47:41 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*buff_dest;
	const unsigned char	*buff_str;

	buff_dest = (unsigned char *)dest;
	buff_str = (const unsigned char *)src;
	while (n--)
		*buff_dest++ = *buff_str++;
	return (dest);
}
