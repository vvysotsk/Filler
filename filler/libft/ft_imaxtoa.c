/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:54:07 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:54:09 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t value)
{
	uintmax_t	index;
	intmax_t	size;
	char		*result;

	index = (value < 0) ? -value : value;
	size = 1 + (value < 0);
	while ((index /= 10))
		size++;
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	index = (value < 0) ? -value : value;
	result[--size] = "0123456789"[index % 10];
	while ((index /= 10))
		result[--size] = "0123456789"[index % 10];
	if (value < 0)
		result[--size] = '-';
	return (result);
}
