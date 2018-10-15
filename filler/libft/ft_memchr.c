/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:41:01 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:46:06 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *src, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((char *)src)[index] == ((char)c))
			return (&((char *)src)[index]);
		++index;
	}
	return (0);
}
