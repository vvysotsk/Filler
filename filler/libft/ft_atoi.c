/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:04:44 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:29:36 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					p_m;

	i = 0;
	result = 0;
	p_m = 1;
	while (str[i] == ' ' || str[i] == '\t' || \
		str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p_m = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i > 19 || result > 9223372036854775807)
		return ((p_m == 1) ? -1 : 0);
	return (result * p_m);
}
