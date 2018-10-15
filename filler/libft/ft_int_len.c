/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:05:25 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:23:27 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_len(int n)
{
	int	counter;
	int	result;

	counter = 0;
	result = n;
	if (result < 0 || result == 0)
	{
		counter++;
		result = -result;
	}
	while (result >= 1)
	{
		result = result / 10;
		counter++;
	}
	return (counter);
}
