/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:18 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:37:21 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_int(char *str, int index, int len, int n)
{
	int		last;

	last = len;
	if (n == 0)
		str[index] = '0';
	index = len;
	while (len > 0)
	{
		len--;
		index--;
		str[index] = n % 10 + '0';
		n = n / 10;
	}
	str[last] = '\0';
	return (str);
}

static char	*write_neg_int(char *str, int index, int len, int n)
{
	int		last;

	n = -n;
	str[0] = '-';
	last = len;
	index = len;
	while (len > 1)
	{
		len--;
		index--;
		str[index] = n % 10 + '0';
		n = n / 10;
	}
	str[last] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		index;

	index = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_int_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (n < 0)
		str = write_neg_int(str, index, len, n);
	else
		str = write_int(str, index, len, n);
	return (str);
}
