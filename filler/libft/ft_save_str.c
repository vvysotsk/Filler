/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:04:26 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:03:00 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_save_str(char **ar_str, const char *str, \
	char delimiter, int str_count)
{
	int		index_str;
	int		index_char;
	int		index;
	int		counter;

	index_str = 0;
	while (str_count-- != 0)
	{
		index = ft_find_nword(str, delimiter, index);
		counter = ft_count_char(str, index, delimiter);
		while (str[index] != delimiter && str[index] != '\0')
		{
			if (!(ar_str[index_str] = (char *)malloc(counter + 1)))
				return (NULL);
			index_char = 0;
			while (str[index] != delimiter && str[index] != '\0')
			{
				ar_str[index_str][index_char++] = str[index++];
			}
			ar_str[index_str][index_char] = '\0';
			index_str++;
		}
	}
	return (ar_str);
}
