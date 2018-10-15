/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:45:50 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:44:12 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned char	*tmp;

	if (size == 0 || (mem = malloc(size)) == 0)
		return (0);
	tmp = (unsigned char *)mem;
	while (size--)
		*tmp++ = 0;
	return (mem);
}
