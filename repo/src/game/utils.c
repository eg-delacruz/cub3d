#include "cub3d.h"

int worldMap[MAP_H][MAP_W] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// -----------------------------------------------------------------------------

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

int		**create_map(void)
{
	int	**map;
	int	i;
	int	j;

	map = (int **)malloc(MAP_H * sizeof(int *));
	i = 0;
	while (i < MAP_H)
	{
		j = 0;
		map[i] = (int *)malloc(MAP_W * sizeof(int));
		while (j < MAP_W)
		{
			map[i][j] = worldMap[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player	*)malloc(sizeof(t_player));

	player->curr_dir[X] = 1;
	player->curr_dir[Y] = 0;
	player->fov = 66;
	player->plane[X] = 0;
	player->plane[Y] = 0.66;
	player->screen_pos[X] = 3.0;
	player->screen_pos[Y] = 3.0;
	player->map_pos[X] = (int)player->screen_pos[X];
	player->map_pos[Y] = (int)player->screen_pos[Y];
	player->radius = 0.3;
	player->speed_mov = 0.33;
	player->speed_rot = 0.001;

	return (player);
}

void	setup_game(t_game *game)
{
	game->player = init_player();
	game->ceiling_color = get_rgba(52, 204, 235, 255);
	game->floor_color = get_rgba(64, 50, 40, 255);
	game->worldMap = create_map();
	game->cursor_blocked = false;
}

void	rotate_dvector(t_dvector *vec, double rot)
{
	double	old_x;

	old_x = (*vec)[X];
	(*vec)[X] = (*vec)[X] * cos(rot) - (*vec)[Y] * sin(rot);
	(*vec)[Y] = old_x * sin(rot) + (*vec)[Y] * cos(rot);
}
