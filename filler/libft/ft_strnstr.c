/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:04:03 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:21:39 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, int len)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = ft_strlen(to_find);
	if (length == 0)
		return ((char *)str);
	length--;
	while (str[i] != '\0' && i < (int)len)
	{
		while (str[i + j] == to_find[j] && i + j < (int)len)
		{
			if (j == length)
				return ((char *)(str + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
