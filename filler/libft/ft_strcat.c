/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:02:13 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:04:22 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	index1;
	int	index2;

	index1 = ft_strlen(dest);
	index2 = 0;
	while (src[index2] != '\0')
	{
		dest[index1] = src[index2];
		++index1;
		++index2;
	}
	dest[index1] = '\0';
	return (dest);
}
