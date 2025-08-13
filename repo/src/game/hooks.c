#include "cub3d.h"

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx);
}

void	block_cursor(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game->cursor_blocked)
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
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
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (close_hook(param));
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
	t_game			*game;
	static double	last_x;
	double			rot;

	game = (t_game *)param;
	last_x = SCREEN_W / 2;
	if (!game->cursor_blocked)
		return ;
	rot = (xpos - last_x) * game->p->speed_rot;
	rotate_dvector(&game->p->curr_dir, rot);
	rotate_dvector(&game->p->plane, rot);
	(void)ypos;
	last_x = xpos;
	mlx_set_mouse_pos(game->mlx, SCREEN_W / 2, SCREEN_H / 2);
	raycasting(game);
}

//  TODO: Hacer hook del cursor y mejorar close_hook;
void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_cursor_hook(game->mlx, mouse_move, game);
}
