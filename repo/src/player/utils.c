#include "cub3d.h"

bool	is_wall_collision(t_map worldMap, double y, double x, double radius)
{
	if (x - radius < 0 || y - radius < 0 ||
		x + radius >= MAP_W || y + radius >= MAP_H)
		return (true);
	if (worldMap[(int)(y - radius)][(int)(x - radius)] != 0 ||
		worldMap[(int)(y - radius)][(int)(x + radius)] != 0 ||
		worldMap[(int)(y + radius)][(int)(x - radius)] != 0 ||
		worldMap[(int)(y + radius)][(int)(x + radius)] != 0)
		return (true);
	if (worldMap[(int)y][(int)(x - radius)] != 0 ||
		worldMap[(int)y][(int)(x + radius)] != 0 ||
		worldMap[(int)(y - radius)][(int)x] != 0 ||
		worldMap[(int)(y + radius)][(int)x] != 0)
		return (true);
	return (false);
}

void	show_player(t_player *player)
{
	printf(MAGENTA"Player info\n"RST);
	printf("curr_dir = { %f , %f }\n", player->curr_dir[X], player->curr_dir[Y]);
	printf("map_pos = { %d , %d }\n", player->map_pos[X], player->map_pos[Y]);
	printf("screen_pos = { %f , %f }\n", player->screen_pos[X], player->screen_pos[Y]);
	printf("plane = { %f , %f }\n", player->plane[X], player->plane[Y]);
	printf("radius = %f, speed_mov = %f, speed_rot = %f\n", player->radius, player->speed_mov, player->speed_rot);
}

void	set_player_dir(t_player	*player, t_direction init_dir)
{
	double	fov;

	fov = player->fov / 100;
	if (!player || init_dir > 3 || init_dir < 0)
		return ;
	if (init_dir == NO)
	{
		set_dvector(&player->curr_dir, 0, -1);
		set_dvector(&player->plane, -fov, 0);
	}
	if (init_dir == SO)
	{
		set_dvector(&player->curr_dir, 0, 1);
		set_dvector(&player->plane, fov, 0);
	}
	if (init_dir == EA)
	{
		set_dvector(&player->curr_dir, 1, 0);
		set_dvector(&player->plane, 0, fov);
	}
	if (init_dir == WE)
	{
		set_dvector(&player->curr_dir, -1, 0);
		set_dvector(&player->plane, 0, -fov);
	}
}
