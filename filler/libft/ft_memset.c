/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:52:52 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:49:35 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t n)
{
	unsigned char ch;
	unsigned char *tmp;

	ch = c & 0xff;
	tmp = (unsigned char *)str;
	while (n--)
		*tmp++ = ch;
	return (str);
}
