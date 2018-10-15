/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sheet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:36:16 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 20:36:18 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_piece					create_piece(int pnum)
{
	t_piece					piece_var;

	if (pnum == 1)
	{
		piece_var.piece = 'O';
		piece_var.piece_last = 'o';
	}
	else if (pnum == 2)
	{
		piece_var.piece = 'X';
		piece_var.piece_last = 'x';
	}
	else
		piece_var.piece = ' ';
	return (piece_var);
}

t_sheet					*new_sheet(int fd)
{
	t_sheet					*sheet;
	int						pnum;
	t_grid					*grid;

	pnum = (int)expand_get_next_line_until(fd, get_player_number);
	if (!pnum)
		return (0);
	grid = (t_grid*)expand_get_next_line_until(fd, generate_map);
	if (!grid)
	{
		free(grid);
		return (0);
	}
	sheet = (t_sheet*)ft_memalloc(sizeof(t_sheet));
	if (!sheet)
	{
		free(grid);
		return (0);
	}
	sheet->mine = create_piece(pnum);
	sheet->enemy = (pnum == 1 ? create_piece(2) : create_piece(1));
	sheet->map = grid;
	sheet->first_round = 1;
	sheet->num_pieces = 0;
	return (sheet);
}
