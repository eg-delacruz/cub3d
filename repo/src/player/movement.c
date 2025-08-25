/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:12:32 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/25 15:21:01 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Rotate the player
 */
void	rotate_player(t_game *game, t_key_mov key)
{
	double		angle;
	double		old_dir_x;
	double		old_plane_x;
	t_player	*p;

	p = game->p;
	if (key == LEFT_ROT)
		angle = 1 * PI / 180 * 4.2;
	else
		angle = -1 * PI / 180 * 4.2;
	old_dir_x = p->curr_dir[X];
	old_plane_x = p->plane[X];
	p->curr_dir[X] = p->curr_dir[X] * cos(angle) - p->curr_dir[1] * sin(angle);
	p->curr_dir[Y] = old_dir_x * sin(angle) + p->curr_dir[Y] * cos(angle);
	p->plane[X] = p->plane[X] * cos(angle) - p->plane[Y] * sin(angle);
	p->plane[Y] = old_plane_x * sin(angle) + p->plane[Y] * cos(angle);
}

/**
 * Move the player back and forward
 */
void	move_player(t_game *game, t_key_mov key)
{
	double		dir;
	t_dvector	new_pos;
	t_player	*p;
	double		move_distance;

	if (key == UP)
		dir = 1;
	else
		dir = -1;
	p = game->p;
	move_distance = p->speed_mov * game->delta_time;
	new_pos[X] = p->pos[X] + (dir * p->curr_dir[X] * move_distance);
	new_pos[Y] = p->pos[Y] + (dir * p->curr_dir[Y] * move_distance);
	if (!is_wall_collision(game, p->pos[X], new_pos[Y], p->radius))
	{
		p->pos[Y] = new_pos[Y];
		p->map_pos[Y] = (int)new_pos[Y];
	}
	if (!is_wall_collision(game, new_pos[X], p->pos[Y], p->radius))
	{
		p->pos[X] = new_pos[X];
		p->map_pos[X] = (int)new_pos[X];
	}
}

/**
 * Move the player left and right
 */
void	strafe_player(t_game *game, t_key_mov key)
{
	double		dir;
	t_dvector	new_pos;
	t_player	*p;
	double		move_distance;

	p = game->p;
	if (key == LEFT)
		dir = -1;
	else
		dir = 1;
	move_distance = p->speed_mov * game->delta_time;
	new_pos[X] = p->pos[X] + (dir * p->curr_dir[Y] * move_distance);
	new_pos[Y] = p->pos[Y] - (dir * p->curr_dir[X] * move_distance);
	if (!is_wall_collision(game, new_pos[X], p->pos[Y], p->radius))
	{
		p->pos[X] = new_pos[X];
		p->map_pos[X] = (int)new_pos[X];
	}
	if (!is_wall_collision(game, p->pos[X], new_pos[Y], p->radius))
	{
		p->pos[Y] = new_pos[Y];
		p->map_pos[Y] = (int)new_pos[Y];
	}
}
