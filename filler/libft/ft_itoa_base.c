/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:53:56 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:53:58 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	unsigned int	i;
	int				size;
	char			*result;

	value = (base != 10 && value < 0) ? -value : value;
	i = (base == 10 && value < 0) ? -value : value;
	size = 1 + (base == 10 && value < 0);
	while ((i /= base))
		size++;
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	i = (base == 10 && value < 0) ? -value : value;
	result[--size] = "0123456789ABCDEF"[i % base];
	while ((i /= base))
		result[--size] = "0123456789ABCDEF"[i % base];
	if ((base == 10) && value < 0)
		result[--size] = '-';
	return (result);
}
