/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:12:37 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/22 00:24:20 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall_collision(t_game *game, double x, double y, double radius)
{
	char	**map;

	map = game->map;
	if (x - radius < 0 || y - radius < 0 || \
x + radius >= game->map_cols || y + radius >= game->map_rows)
		return (true);
	if (map[(int)(y - radius)][(int)(x - radius)] != '0' ||
		map[(int)(y - radius)][(int)(x + radius)] != '0' ||
		map[(int)(y + radius)][(int)(x - radius)] != '0' ||
		map[(int)(y + radius)][(int)(x + radius)] != '0')
	{
		return (true);
	}
	if (map[(int)y][(int)(x - radius)] != '0' ||
		map[(int)y][(int)(x + radius)] != '0' ||
		map[(int)(y - radius)][(int)x] != '0' ||
		map[(int)(y + radius)][(int)x] != '0')
		return (true);
	return (false);
}

void	show_player(t_player *player)
{
	printf(MAGENTA"Pla yer info\n"RST);
	printf("init_dir = { %c }\n", (char)player->init_dir);
	printf("curr_dir = { %f , %f }\n", player->curr_dir[X], \
player->curr_dir[Y]);
	printf("map_pos = { %d , %d }\n", player->map_pos[X], player->map_pos[Y]);
	printf("pos = { %f , %f }\n", player->pos[X], player->pos[Y]);
	printf("plane = { %f , %f }\n", player->plane[X], player->plane[Y]);
	printf("radius = %f, speed_mov = %f, speed_rot = %f\n", \
player->radius, player->speed_mov, player->speed_rot);
}

void	set_player_dir(t_player	*player, t_direction init_dir)
{
	double	fov;

	fov = player->fov / 100;
	if (!player)
		return ;
	if (init_dir == N)
	{
		set_dvector(&player->curr_dir, 0, -1);
		set_dvector(&player->plane, -fov, 0);
	}
	if (init_dir == S)
	{
		set_dvector(&player->curr_dir, 0, 1);
		set_dvector(&player->plane, fov, 0);
	}
	if (init_dir == E)
	{
		set_dvector(&player->curr_dir, 1, 0);
		set_dvector(&player->plane, 0, fov);
	}
	if (init_dir == W)
	{
		set_dvector(&player->curr_dir, -1, 0);
		set_dvector(&player->plane, 0, -fov);
	}
}
