/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:28:39 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:17:57 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			index1;
	unsigned int	index2;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s[index1] != '\0')
	{
		str[index1] = f(index2++, s[index1]);
		index1++;
	}
	str[index1] = '\0';
	return (str);
}
