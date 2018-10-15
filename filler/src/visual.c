/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:48:51 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 21:48:52 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <ncurses.h>

void					visualizer_reinit(void)
{
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_GREEN, COLOR_GREEN);
}

int						select_color(char p)
{
	if (p == 'O')
		return (3);
	else if (p == 'X')
		return (2);
	else
		return (1);
}

void					visualize(t_sheet *sheet)
{
	int				row;
	int				column;
	int				cpair;

	row = -1;
	column = -1;
	while (++row < sheet->map->rows)
	{
		column = -1;
		while (++column < sheet->map->columns)
		{
			cpair = select_color(sheet->map->grid[row][column]);
			if (cpair != 1)
				mvchgat(row, column * 3, 3, 0, cpair, 0);
		}
	}
	refresh();
	usleep(10000);
}

void					visualizer_init(void)
{
	newterm(NULL, stderr, stdout);
	start_color();
	noecho();
	curs_set(0);
	visualizer_reinit();
}
