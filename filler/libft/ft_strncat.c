/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:03:03 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:19:00 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	index1;
	size_t	index2;

	index1 = ft_strlen(dest);
	index2 = 0;
	while (src[index2] != '\0' && index2 < n)
	{
		dest[index1] = src[index2];
		++index1;
		++index2;
	}
	dest[index1] = '\0';
	return (dest);
}
