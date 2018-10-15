/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:24:23 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:20:04 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*buff;
	char	*new_str;

	if ((buff = (char *)malloc(sizeof(char) * size + 1)) == 0)
		return (0);
	new_str = buff;
	while (size--)
		*buff++ = '\0';
	*buff = '\0';
	return (new_str);
}
