/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:03:17 by vvysotsk          #+#    #+#             */
/*   Updated: 2017/12/21 16:03:18 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	cated_dest_size;

	i = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (dest[i] && i < destsize)
		i++;
	cated_dest_size = i;
	while (src[i - cated_dest_size] && i < destsize - 1)
	{
		dest[i] = src[i - cated_dest_size];
		i++;
	}
	if (cated_dest_size < destsize)
		dest[i] = '\0';
	return (cated_dest_size + ft_strlen(src));
}
