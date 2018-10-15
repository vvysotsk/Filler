/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:08 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:22:53 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		str_count;
	char	**ar_str;

	if (!s)
		return (NULL);
	str_count = ft_count_str(s, c);
	ar_str = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!ar_str)
		return (0);
	ar_str = ft_save_str(ar_str, s, c, str_count);
	if (!ar_str)
		return (NULL);
	ar_str[str_count] = NULL;
	return (ar_str);
}
