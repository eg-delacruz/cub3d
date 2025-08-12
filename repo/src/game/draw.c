#include "cub3d.h"

void draw_ver_line(t_game *game, int x, int start, int end, int32_t color)
{
	int temp;
	int i = -1;

	if (!game->image)
		return;
	if (start < 0 || start > SCREEN_H)
		return;
	if (end < 0 || end > SCREEN_H)
		return;
	if (start > end)
	{
		temp = end;
		end = start;
		start = temp;
	}
	while (++i < start)
		mlx_put_pixel(game->image, x, i, game->c);
	while (start < end)
	{
		mlx_put_pixel(game->image, x, start, color);
		start++;
	}
	i = end - 1;
	while (++i < SCREEN_H)
		mlx_put_pixel(game->image, x, i, game->f);
}
