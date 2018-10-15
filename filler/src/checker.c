/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:34:39 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:34:41 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int						msize(int n)
{
	int					c;

	c = 0;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		c++;
	}
	return (c + 1);
}

int						get_min_y(t_sheet *sheet, int c, int y)
{
	if (sheet->token[1] > c)
		return (-sheet->token[1]);
	(void)y;
	return (0);
}

int						get_distance(t_location a, t_location b)
{
	int					diffx;
	int					diffy;

	diffx = (a.x - b.x);
	diffy = (a.y - b.y);
	diffx = (diffx < 0 ? diffx * -1 : diffx);
	diffy = (diffy < 0 ? diffy * -1 : diffy);
	return (diffx + diffy);
}

t_location				scan_map_forward(t_grid *grid,
							t_location loc, t_piece match)
{
	t_location			curloc;

	curloc = loc;
	while (curloc.x < grid->rows)
	{
		while (curloc.y < grid->columns)
		{
			if (grid->grid[curloc.x][curloc.y] == match.piece)
				return (curloc);
			curloc.y++;
		}
		curloc.y = 0;
		curloc.x++;
	}
	return (curloc);
}

t_location				scan_map_backward(t_grid *grid,
							t_location loc, t_piece match)
{
	t_location			curloc;

	curloc = loc;
	while (curloc.x >= 0)
	{
		while (curloc.y >= 0)
		{
			if (grid->grid[curloc.x][curloc.y] == match.piece)
				return (curloc);
			curloc.y--;
		}
		curloc.y = grid->columns - 1;
		curloc.x--;
	}
	return (curloc);
}
