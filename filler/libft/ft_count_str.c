/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:08:24 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 18:32:20 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_str(const char *s, char delimiter)
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while (s[index] != '\0')
	{
		while (s[index] == delimiter)
			index++;
		if (s[index] != '\0')
			counter++;
		while (s[index] != delimiter && s[index] != '\0')
			index++;
	}
	return (counter);
}
