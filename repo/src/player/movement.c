/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:12:32 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/22 00:12:33 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/**
 * Rotate the player
 */
void rotate_player(t_game *game, t_key_mov key)
{
	double angle;
	double old_dir_x;
	double old_plane_x;
	t_player *player = game->p;

	if (key == LEFT_ROT)
		angle = 1 * PI / 180 * 4.2;
	else
		angle = -1 * PI / 180 * 4.2;
	old_dir_x = player->curr_dir[X];
	old_plane_x = player->plane[X];
	printf("old_dir x -> %f y -> %f\n", player->curr_dir[X], player->curr_dir[Y]);
	player->curr_dir[X] = player->curr_dir[X] * cos(angle) - player->curr_dir[1] * sin(angle);
	player->curr_dir[Y] = old_dir_x * sin(angle) + player->curr_dir[Y] * cos(angle);
	player->plane[X] = player->plane[X] * cos(angle) - player->plane[Y] * sin(angle);
	player->plane[Y] = old_plane_x * sin(angle) + player->plane[1] * cos(angle);
	printf("new_dir x -> %f y -> %f\n", player->curr_dir[X], player->curr_dir[Y]);
	raycasting(game);
}

/**
 * Move the player back and forward
 */
void move_player(t_game *game, t_key_mov key)
{
	double dir;
	t_dvector new_pos;
	t_player *player;

	if (key == UP)
		dir = 1;
	else
		dir = -1;
	player = game->p;
	printf("curr_pos X -> %d Y -> %d\n", (int)player->map_pos[Y], (int)player->map_pos[X]);
	new_pos[X] = player->pos[X] + (dir * player->curr_dir[X] * player->speed_mov);
	new_pos[Y] = player->pos[Y] + (dir * player->curr_dir[Y] * player->speed_mov);
	printf("Trying to move to worldMap[%f][%f]\n", new_pos[Y], new_pos[X]);
	if (!is_wall_collision(game, player->pos[X], new_pos[Y],player->radius))
	{
		player->pos[Y] = new_pos[Y];
		player->map_pos[Y] = (int)new_pos[Y];
	}
	if (!is_wall_collision(game, new_pos[X], player->pos[Y], player->radius))
	{
		player->pos[X] = new_pos[X];
		player->map_pos[X] = (int)new_pos[X];
	}
	printf("curr_pos X -> %f Y -> %f\n", player->pos[X], player->pos[Y]);
	raycasting(game);
}

/**
 * Move the player left and right
 */
void strafe_player(t_game *game, t_key_mov key)
{
	double dir;
	t_dvector new_pos;
	t_player *player;

	if (key == LEFT)
		dir = -1;
	else
		dir = 1;
	player = game->p;
	printf("curr_pos X -> %d Y -> %d\n", (int)player->pos[Y], (int)player->pos[X]);
	new_pos[X] = player->pos[X] + (dir * player->curr_dir[Y] * player->speed_mov);
	new_pos[Y] = player->pos[Y] - (dir * player->curr_dir[X] * player->speed_mov);
	if (!is_wall_collision(game, new_pos[X], player->pos[Y], player->radius))
	{
		player->pos[X] = new_pos[X];
		player->map_pos[X] = (int)new_pos[X];
	}
	printf("Trying to move to worldMap[%f][%f] = %d\n", new_pos[Y], new_pos[X], game->map[(int)new_pos[Y]][(int)new_pos[X]]);
	if (!is_wall_collision(game, player->pos[X], new_pos[Y], player->radius))
	{
		player->pos[Y] = new_pos[Y];
		player->map_pos[Y] = (int)new_pos[Y];
	}
	printf("strafe_pos X -> %f Y -> %f\n", player->pos[X], player->pos[Y]);
	raycasting(game);
}
