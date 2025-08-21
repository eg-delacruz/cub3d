/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:42:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/21 14:43:27 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_mlx(t_game	*game)
{
	game->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3D", true);
	if (!game->mlx)
		return (false);
	game->image = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	if (!game->image)
	{
		mlx_close_window(game->mlx);
		printf(RED"Error %s\n"RST, mlx_strerror(mlx_errno));
		mlx_terminate(game->mlx);
		return (false);
	}
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		printf(RED"Error %s\n"RST, mlx_strerror(mlx_errno));
		mlx_terminate(game->mlx);
		return (false);
	}
	return (true);
}

static void	prepare_player(t_player *p)
{
	if (!p)
		return ;
	p->fov = FOV;
	set_player_dir(p, p->init_dir);
	set_dvector(&p->pos, (double)p->init_pos[X] + 0.5, \
(double)p->init_pos[Y] + 0.5);
	set_ivector(&p->map_pos, p->init_pos[X], p->init_pos[Y]);
	p->radius = 0.01;
	p->speed_mov = 0.33;
	p->speed_rot = 0.001;
}

bool	setup_game(t_game *game)
{
	prepare_player(game->p);
	game->cursor_blocked = false;
	if (!init_mlx(game))
		return (free_game(game), false);
	if (!load_textures(game))
		return (free_game(game), false);
	setup_hooks(game);
	return (true);
}
