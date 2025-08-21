/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:12:10 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/22 00:52:40 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_tex_pixel(mlx_texture_t *tex, int x, int y)
{
	int		index;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	index = (y * tex->width + x) * tex->bytes_per_pixel;
	r = tex->pixels[index];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	a = tex->pixels[index + 3];
	return (get_rgba((uint32_t)r, (uint32_t)g, (uint32_t)b, (uint32_t)a));
}

static void	get_tex_ratio(t_wall *wall, double *start, double *end)
{
	if (wall->height > SCREEN_H)
	{
		*start = (double)(wall->height - SCREEN_H) / 2.0 / wall->height;
		*end = 1.0 - *start;
	}
	else
	{
		*start = 0.0;
		*end = 1.0;
	}
}

void	draw_ver_line(t_game *game, int x, t_wall *wall, int tex_x)
{
	int			y;
	int			tex_y;
	double		r_start;
	double		r_end;
	double		screen_y_ratio;

	get_tex_ratio(wall, &r_start, &r_end);
	y = wall->start - 1;
	while (++y <= wall->end)
	{
		screen_y_ratio = (double)(y - wall->start) / \
(double)(wall->end - wall->start);
		tex_y = (int)((r_start + screen_y_ratio * (r_end - r_start)) * \
wall->tex->height);
		if ((uint32_t)tex_y >= wall->tex->height)
			tex_y = wall->tex->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
		{
			mlx_put_pixel(game->image, x, y, \
get_tex_pixel(wall->tex, tex_x, tex_y));
		}
	}
}
