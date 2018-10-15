/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:03:50 by vvysotsk          #+#    #+#             */
/*   Updated: 2017/12/21 16:03:51 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (to_find[length] != '\0')
		length++;
	if (length == 0)
		return ((char *)str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
		{
			if (j == length - 1)
				return ((char *)(str + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
