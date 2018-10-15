/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:07:36 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:24:05 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_nword(const char *str, char delimiter, int index)
{
	while (str[index] == delimiter)
		index++;
	return (index);
}
