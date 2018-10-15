/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:29:17 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:24:01 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = 0;
	str = (char *)malloc(len + 1);
	if (str && s)
	{
		while (len--)
		{
			str[index] = s[start];
			index++;
			start++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
