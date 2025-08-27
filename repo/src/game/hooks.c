/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:12:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/27 10:36:25 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	block_cursor(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game->cursor_blocked)
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		mlx_set_mouse_pos(game->mlx, SCREEN_W / 2, SCREEN_H / 2);
		game->cursor_blocked = true;
	}
	else
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
		game->cursor_blocked = false;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		return (mlx_close_window(game->mlx));
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
		return (block_cursor(param));
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			return (move_player(game, UP));
		if (keydata.key == MLX_KEY_S)
			return (move_player(game, DOWN));
		if (keydata.key == MLX_KEY_A)
			return (strafe_player(game, LEFT));
		if (keydata.key == MLX_KEY_D)
			return (strafe_player(game, RIGHT));
		if (keydata.key == MLX_KEY_RIGHT)
			return (rotate_player(game, RIGHT_ROT));
		if (keydata.key == MLX_KEY_LEFT)
			return (rotate_player(game, LEFT_ROT));
	}
}

void	mouse_move(double xpos, double ypos, void *param)
{
	t_game				*game;
	static t_dvector	last = {-1.0, -1.0};
	double				delta_x;
	double				rot;

	game = (t_game *)param;
	if (!game->cursor_blocked)
		return (set_dvector(&last, -1, -1));
	if (last[X] < 0)
		return (set_dvector(&last, xpos, ypos));
	delta_x = xpos - last[X];
	rot = get_rot(delta_x);
	if (fabs(rot) > 0.001)
	{
		rotate_dvector(&game->p->curr_dir, rot);
		rotate_dvector(&game->p->plane, rot);
	}
	set_dvector(&last, xpos, ypos);
	if (fabs(xpos - SCREEN_W / 2) > SCREEN_W / 4 || \
fabs(ypos - SCREEN_H / 2) > SCREEN_H / 4)
	{
		mlx_set_mouse_pos(game->mlx, SCREEN_W / 2, SCREEN_H / 2);
		set_dvector(&last, SCREEN_W / 2, SCREEN_H / 2);
	}
}

void	update_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->delta_time = get_delta_time(&game->last_time_frame);
	raycasting(game);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_cursor_hook(game->mlx, mouse_move, game);
	mlx_loop_hook(game->mlx, update_game, game);
}
