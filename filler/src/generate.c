/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:34:49 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:35:07 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int							is_gud(t_sheet *sheet, int x, int y, int idx)
{
	int						nx;
	int						ny;

	nx = x;
	ny = (y < 0 && x > 0 ? (sheet->map->columns) + y : y);
	if (nx >= sheet->map->rows || ny >= sheet->map->columns || nx < 0)
		return (0);
	else if (sheet->map->grid[nx][ny] == sheet->enemy.piece)
		return (0);
	else if (sheet->token[idx + 1] + ny < 0)
		return (0);
	else if (sheet->map->grid[nx][ny] == sheet->mine.piece
			|| sheet->map->grid[nx][ny] == sheet->mine.piece_last)
		return (2);
	return (1);
}

t_foundpiece				*check_piece(t_sheet *sheet, int x, int y)
{
	t_foundpiece			*piece;
	int						i;
	int						res;

	piece = (t_foundpiece*)ft_memalloc(sizeof(t_foundpiece));
	if (!piece)
		return (0);
	piece->loc.x = x;
	piece->loc.y = y;
	i = 0;
	while (sheet->token[i] != -2147483648)
	{
		res = is_gud(sheet, (x + sheet->token[i]), (y + sheet->token[i + 1]), i);
		if (res == 0)
		{
			free(piece);
			return (0);
		}
		else if (res == 2)
			piece->intersects += 1;
		i += 2;
	}
	if (piece->intersects != 1)
		ft_memdel((void**)&piece);
	return (piece);
}

t_foundpiece				*get_piece(t_sheet *sheet, int curx,
								int cury, int value)
{
	t_foundpiece			*ohgoodwillpls;

	while (curx >= 0 && curx < sheet->map->rows)
	{
		while (cury >= get_min_y(sheet, cury, 1) && cury < sheet->map->columns)
		{
			ohgoodwillpls = check_piece(sheet, curx, cury);
			if (ohgoodwillpls)
				return (ohgoodwillpls);
			cury += value;
		}
		cury = cury < 0 ? sheet->map->columns - 1 : 0;
		curx += value;
	}
	return (0);
}

t_foundpiece				*get_effective_piece(t_sheet *sheet,
								t_location loc, int value)
{
	t_foundpiece			*current;
	t_location				next;
	t_foundpiece			*new;

	current = get_piece(sheet, loc.x, loc.y, value);
	if (!current)
		return (0);
	next.x = current->loc.x;
	next.y = current->loc.y + value;
	new = get_effective_piece(sheet, next, value);
	if (!new && current)
		return (current);
	else if (!new)
		return (0);
	if (get_distance(current->loc, sheet->enemy_last_piece)
			<= get_distance(new->loc, sheet->enemy_last_piece))
	{
		free((sheet->mine.piece == 'X' ? new : current));
		return ((sheet->mine.piece == 'X' ? current : new));
	}
	(new ? free(new) : 0);
	return (current);
}

t_foundpiece				*select_algorithm(t_sheet *sheet, t_location loc)
{
	t_foundpiece			*found;

	found = get_effective_piece(sheet, loc, -1);
	if (!found)
		found = get_effective_piece(sheet, loc, 1);
	return (found);
}
