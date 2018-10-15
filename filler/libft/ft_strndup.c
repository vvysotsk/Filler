/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:07:34 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/02/07 00:07:35 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *str, size_t n)
{
	char	*buff;
	char	*dest;

	if (!(buff = ft_strnew(n + 1)))
		return (0);
	dest = buff;
	n++;
	while (--n > 0)
		*buff++ = *str++;
	*buff = '\0';
	return (dest);
}
