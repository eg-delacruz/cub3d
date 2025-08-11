/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:55:34 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/18 10:55:34 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (puterror(ERR_INIT_GAME), NULL);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->map_rows = 0;
	game->map_cols = 0;
	game->p = NULL;
	game->c[3] = -1;
	game->f[3] = -1;
	return (game);
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

static void	init_parse(t_game *game)
{
	game->parse.c_color_str = NULL;
	game->parse.f_color_str = NULL;
	game->parse.file_path = NULL;
	game->parse.raw_map = NULL;
	game->parse.map_till_eof_lines = 0;
	game->parse.flood_check_map = NULL;
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
