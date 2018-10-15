/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:22:28 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/07 23:22:29 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_islen(int ch)
{
	if (ch == 'h' || ch == 'l' || ch == 'j' || ch == 'z')
		return (1);
	return (0);
}

int		ft_intcmp(int x, int y)
{
	return (((x) > (y)) ? (x) : (y));
}

int		ft_up(int ch)
{
	return (((unsigned)ch - 97) < 26u ? ch - 32 : ch);
}
