/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:53:00 by vvysotsk          #+#    #+#             */
/*   Updated: 2018/10/15 13:53:01 by vvysotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct			s_location
{
	int					x;
	int					y;
}						t_location;

typedef struct			s_piece
{
	char				piece;
	char				piece_last;
}						t_piece;

typedef struct			s_grid
{
	char				*buffer;
	char				**grid;
	int					rows;
	int					columns;
}						t_grid;

typedef struct			s_sheet
{
	t_grid				*map;
	int					*token;
	int					first_round;
	int					sheet_won;
	int					enemy_tetr;
	int					num_pieces;
	t_piece				enemy;
	t_piece				mine;
	t_location			enemy_last_piece;
	t_location			last_placed_piece;
}						t_sheet;

typedef struct			s_foundpiece
{
	t_location			loc;
	int					intersects;
}						t_foundpiece;

void					*get_player_number(int fd, char *line);
void					*generate_map(int fd, char *line);
void					*token_parse(int fd, char *line);
t_grid					*grid_fill(t_sheet *sheet, int fd);
int						msize(int n);
t_grid					*grid_new(int x, int y);
t_sheet					*new_sheet(int fd);
int						play(t_sheet *sheet);
int						get_distance(t_location a, t_location b);
int						get_min_y(t_sheet *sheet, int c, int y);
t_location				scan_map_forward(t_grid *grid, t_location loc, t_piece match);
t_location				scan_map_backward(t_grid *grid, t_location loc, t_piece match);
t_foundpiece			*select_algorithm(t_sheet *sheet, t_location loc);
void					*expand_get_next_line_until(int fd, void *(*f)(int, char*));
void					visualizer_reinit(void);
int						select_color(char p);
void					visualize(t_sheet *sheet);
void					visualizer_init(void);
#endif
