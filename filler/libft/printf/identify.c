/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:24:50 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/07 21:24:51 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isx(int c)
{
	if (((unsigned)c | 32) - 97 == 23u)
		return (1);
	return (0);
}

int		ft_is0(int c)
{
	if (((unsigned)c | 32) - 97 == 14u)
		return (1);
	return (0);
}

int		ft_x_or_0(int c)
{
	if ((ft_isx(c)) || (ft_is0(c)))
		return (1);
	return (0);
}

int		ft_alpha(int ch)
{
	if (((unsigned)ch | 32) - 97 < 26u)
		return (1);
	return (0);
}

int		ft_digit(int ch)
{
	if (((unsigned)ch - 48) < 10u)
		return (1);
	return (0);
}
