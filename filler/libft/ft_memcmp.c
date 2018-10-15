/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:36:22 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:47:03 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *dest, const void *src, size_t n)
{
	size_t	index;

	if (dest == src || n == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		if (((unsigned char *)dest)[index] == ((unsigned char *)src)[index])
			++index;
		else
			return (((unsigned char *)dest)[index] - \
				((unsigned char *)src)[index]);
	}
	return (0);
}
