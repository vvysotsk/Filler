/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:35:38 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:35:39 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					*expand_get_next_line_until(int fd,
							void *(*f)(int, char*))
{
	char					*line;
	void					*result;

	result = 0;
	line = 0;
	while (get_next_line(fd, &line))
	{
		result = f(fd, line);
		free(line);
		if (result)
			return (result);
	}
	return (0);
}

int						*iterate_token(int fd, int x, int y)
{
	int					*tokenoff;
	int					curx;
	int					cury;
	int					arrindex;
	char				*line;

	line = 0;
	curx = -1;
	cury = -1;
	arrindex = 0;
	tokenoff = (int*)ft_memalloc(sizeof(int*) * 2 * ((x * y)));
	while (++curx < x && get_next_line(fd, &line) == 1)
	{
		cury = -1;
		while (++cury < y)
			if (line[cury] == '*')
			{
				tokenoff[arrindex++] = curx;
				tokenoff[arrindex++] = cury;
			}
		free(line);
	}
	tokenoff[arrindex++] = -2147483648;
	return (tokenoff);
}

void					*token_parse(int fd, char *line)
{
	int					x;
	int					y;

	if (ft_strstr(line, "Piece "))
	{
		x = ft_atoi(line + 6);
		if (!x)
			return (0);
		y = ft_atoi(line + 6 + msize(x));
		if (!y)
			return (0);
		return (iterate_token(fd, x, y));
	}
	return (0);
}
