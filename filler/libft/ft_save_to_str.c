/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:54:23 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/04 17:54:24 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_save_to_str(char **s1, char *s2)
{
	char *buff;
	char *s1_tmp;
	char *new_str;

	if (!s1 || !s2)
		return ;
	new_str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1);
	buff = new_str;
	s1_tmp = *s1;
	while (*s2)
		*buff++ = *s2++;
	while (*s1_tmp)
		*buff++ = *s1_tmp++;
	*buff = '\0';
	free(*s1);
	*s1 = new_str;
}
