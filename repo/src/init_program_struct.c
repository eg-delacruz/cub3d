/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:55:34 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/24 15:52:40 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (puterror(ERR_INIT_GAME), NULL);
	game->p = NULL;
	game->no_tex_path = NULL;
	game->so_tex_path = NULL;
	game->we_tex_path = NULL;
	game->ea_tex_path = NULL;
	game->no_tex = NULL;
	game->so_tex = NULL;
	game->we_tex = NULL;
	game->ea_tex = NULL;
	game->c = -1;
	game->f = -1;
	game->map_rows = 0;
	game->map_cols = 0;
	game->map = NULL;
	gettimeofday(&game->last_time_frame, NULL);
	return (game);
}

static void	init_parse(t_game *game)
{
	game->parse.c_color_str = NULL;
	game->parse.f_color_str = NULL;
	game->parse.file_path = NULL;
	game->parse.raw_map = NULL;
	game->parse.map_till_eof_lines = 0;
	game->parse.flood_check_map = NULL;
}

static int	init_player(t_game *game)
{
	game->p = malloc(sizeof(t_player));
	if (!game->p)
		return (ft_safe_free((void **)&game), 1);
	game->p->pos[0] = -1;
	game->p->pos[1] = -1;
	game->p->init_pos[0] = -1;
	game->p->init_pos[1] = -1;
	game->p->init_dir = '0';
	game->p->curr_dir[0] = 0;
	game->p->curr_dir[1] = 0;
	return (0);
}

t_game	*init_program_struct(void)
{
	t_game	*game;

	game = init_game();
	if (!game)
		return (NULL);
	if (init_player(game) == 1)
		return (NULL);
	init_parse(game);
	return (game);
}
