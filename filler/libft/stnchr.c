/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stnchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:05:04 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:05:05 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnchr(const char *s, int c, size_t size)
{
	ssize_t					len;

	len = -1;
	while (++len < (ssize_t)size && (unsigned char)*s != (unsigned char)c && *s)
		(void)*s++;
	if (len >= (ssize_t)size || (!*s && c != 0))
		return (0);
	return ((char*)s);
}
