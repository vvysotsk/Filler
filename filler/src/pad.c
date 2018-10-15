/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:13:40 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 14:13:41 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_foundpiece			*place_piece(t_sheet *sheet)
{
	t_location			a;
	t_location			b;
	t_foundpiece		*matcha;
	t_foundpiece		*matchb;

	if (sheet->enemy_last_piece.x == -1)
		return (select_algorithm(sheet, sheet->last_placed_piece));
	a = scan_map_backward(sheet->map, sheet->enemy_last_piece, sheet->mine);
	b = scan_map_forward(sheet->map, sheet->enemy_last_piece, sheet->mine);
	matcha = select_algorithm(sheet, a);
	if (matcha && matcha->intersects == 1)
		return (matcha);
	matchb = select_algorithm(sheet, b);
	if (!matcha)
		return (matchb);
	else if (!matchb)
		return (matcha);
	else if (get_distance(matcha->loc, sheet->enemy_last_piece) \
		<= get_distance(matchb->loc, sheet->enemy_last_piece))
	{
		free(sheet->mine.piece == 'X' ? matcha : matchb);
		return (sheet->mine.piece == 'X' ? matchb : matcha);
	}
	(matchb ? free(matchb) : 0);
	return (matchb);
}

int						play(t_sheet *sheet)
{
	int					tries;
	t_foundpiece		*match;

	tries = 0;
	while (tries < 10 && !grid_fill(sheet, 0))
		tries++;
	if (tries >= 10)
		return (0);
	sheet->token = (int*)expand_get_next_line_until(0, token_parse);
	if (sheet->token == 0)
		return (0);
	match = place_piece(sheet);
	if (!match)
		return (0);
	ft_printf("%d %d\n", match->loc.x, match->loc.y);
	sheet->num_pieces++;
	free(match);
	return (1);
}
