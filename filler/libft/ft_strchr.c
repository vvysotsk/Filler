/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:02:36 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:05:49 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	find;

	find = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == find)
		return ((char *)(str + i));
	return (NULL);
}
