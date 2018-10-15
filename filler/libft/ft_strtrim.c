/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:29:48 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/01/17 19:29:05 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_first_letter(const char *str)
{
	int		index;

	index = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\n') && str++)
		index++;
	return (index);
}

static int	ft_last_letter(const char *str)
{
	int		index;

	if (!*str)
		return (0);
	index = ft_strlen(str);
	str += index - 1;
	while ((*str == ' ' || *str == '\t' || *str == '\n') && --index)
		str--;
	return (index);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		end;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	start = ft_first_letter(s);
	end = ft_last_letter(s);
	if (start <= end && end != 0)
	{
		if (!(str = (char *)malloc(end - start + 1)))
			return (0);
		while (start < end)
			str[index++] = s[start++];
	}
	else if ((str = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	str[index] = '\0';
	return (str);
}
