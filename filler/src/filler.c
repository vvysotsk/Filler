/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:11:36 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 14:11:38 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <ncurses.h>

int				main(int ac, char **av)
{
	t_sheet		*sheet;
	int			visualizer;

	sheet = new_sheet(0);
	if (!sheet)
	{
		ft_printf("Error\n");
		return (0);
	}
	sheet->enemy_tetr = 0;
	visualizer = 0;
	if (ac == 2 && ft_strequ(av[1], "-v"))
	{
		visualizer_init();
		visualizer = 1;
	}
	while (play(sheet))
	{
		if (visualizer)
			visualize(sheet);
	}
	(void)ac;
	(void)av;
	return (0);
}