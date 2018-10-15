/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:02:27 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:31:44 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_char(const char *str, int index, char delimiter)
{
	int	counter;

	counter = 0;
	while (str[index] != delimiter && str[index] != '\0')
	{
		index++;
		counter++;
	}
	return (counter);
}
