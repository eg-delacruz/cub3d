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

# include "cub3d.h"

// TODO: initialize all elements in a different function depending on its category
t_game *init_game_struct(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->NO_texture = NULL;
	game->SO_texture = NULL;
	game->WE_texture = NULL;
	game->EA_texture = NULL;
	game->map_height = 0;
	game->map_length = 0;
	game->p = NULL;
	
	// Player
	game->p = malloc(sizeof(t_player));
	if (!game->p)
		return (ft_safe_free((void **)&game), NULL);
	game->p->init_pos = NULL;
	game->p->pos = NULL;
	game->p->pos = malloc(sizeof(t_pos));
	game->p->init_pos = malloc(sizeof(t_pos));
	if (!game->p->pos || !game->p->init_pos)
	{
		ft_safe_free((void **)&game->p->pos);
		ft_safe_free((void **)&game->p->init_pos);
		ft_safe_free((void **)&game->p);
		ft_safe_free((void **)&game);
		return (NULL);
	}
	game->p->pos->x = -1;
	game->p->pos->y = -1;

	// Parse
	game->parse.C_color_str = NULL;
	game->parse.F_color_str = NULL;
	game->parse.file_path = NULL;
	game->parse.raw_map = NULL;
	game->parse.map_till_eof_lines = 0;
	return (game);
}
