/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:00:48 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:00:49 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*expand_pad(char c, int repeat, char *result, int *bsize)
{
	char				*tmp;

	tmp = ft_strnew(repeat);
	ft_memset(tmp, c, repeat);
	result = expand_write(tmp, repeat, result, bsize);
	free(tmp);
	return (result);
}
