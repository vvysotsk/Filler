/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:29:32 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:14:45 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		index_src;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	index_src = 0;
	while (s1[index_src] != '\0')
	{
		str[index] = s1[index_src];
		index_src++;
		index++;
	}
	index_src = 0;
	while (s2[index_src] != '\0')
	{
		str[index] = s2[index_src];
		index_src++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
