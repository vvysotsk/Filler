/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_fig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:36:10 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:36:11 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Grid Positioning System
*/

void					grid_init(t_grid *grid)
{
	int					i;
	int					j;

	i = -1;
	while (++i < grid->rows)
	{
		grid->grid[i] = grid->buffer + (i * (grid->columns + 1));
		j = -1;
		while (++j < grid->columns)
			grid->grid[i][j] = '.';
		grid->grid[i][j] = '\n';
	}
	grid->buffer[(grid->rows * grid->columns + 1) + grid->columns - 2] = '\0';
}

t_grid					*grid_new(int x, int y)
{
	t_grid				*new;

	new = (t_grid*)ft_memalloc(sizeof(t_grid));
	new->buffer = (char*)ft_memalloc(sizeof(char) * ((x + 1) * (y + 1)));
	new->grid = (char**)ft_memalloc(sizeof(char*) * x);
	new->rows = x;
	new->columns = y;
	grid_init(new);
	return (new);
}

int						last_place_or_first(t_sheet *sheet, int curx, int cury)
{
	if (sheet->enemy_last_piece.x != -1)
		return (0);
	return (sheet->map->grid[curx][cury] == '.');
}

int						parse_line(char *line, int curx, t_sheet *sheet)
{
	int					cury;

	cury = -1;
	while (++cury < sheet->map->columns)
	{
		if (line[cury] != 'O' && line[cury] != 'X' && line[cury] != '.')
			return (0);
		if (last_place_or_first(sheet, curx, cury)
				&& line[cury] == sheet->enemy.piece)
		{
			sheet->enemy_last_piece.x = curx;
			sheet->enemy_last_piece.y = cury;
		}
		else if (sheet->first_round && line[cury] == sheet->mine.piece)
		{
			sheet->last_placed_piece.x = curx;
			sheet->last_placed_piece.y = cury;
		}
		sheet->map->grid[curx][cury] = line[cury];
	}
	return (1);
}

t_grid					*grid_fill(t_sheet *sheet, int fd)
{
	t_grid				*grid;
	int					curx;
	char				*line;

	grid = sheet->map;
	line = 0;
	curx = 0;
	while (get_next_line(fd, &line))
	{
		if (!parse_line(line + 4, curx++, sheet))
		{
			free(line);
			return (0);
		}
		free(line);
		if (curx >= sheet->map->rows)
			break ;
	}
	return (grid);
}
