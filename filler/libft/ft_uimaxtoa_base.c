/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:54:40 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:54:41 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	uintmax_t	i;
	size_t		size;
	char		*result;

	i = value;
	size = 1;
	while ((i /= base))
		size++;
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	i = value;
	result[--size] = str[i % base];
	while ((i /= base))
		result[--size] = str[i % base];
	return (result);
}
