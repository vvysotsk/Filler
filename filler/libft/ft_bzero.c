/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:07:01 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:30:48 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_bzero(void *str, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((char*)str)[index] = 0;
		++index;
	}
	return (str);
}
