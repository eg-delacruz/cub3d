/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:12:10 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/22 00:20:37 by jtivan-r         ###   ########.fr       */
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

void	draw_ver_line(t_game *game, int x, t_wall *wall, int tex_x)
{
	int			y;
	int			tex_y;
	double		tex_ratio;
	int			visible_h;
	uint32_t	color;

	visible_h = wall->end - wall->start + 1;
	y = wall->start - 1;
	while (++y <= wall->end)
	{
		tex_ratio = (double)(y - wall->start) / (double)visible_h;
		tex_y = (int)(tex_ratio * wall->tex->height);
		if ((uint32_t)tex_y >= wall->tex->height)
			tex_y = wall->tex->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = get_tex_pixel(wall->tex, tex_x, tex_y);
		if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
			mlx_put_pixel(game->image, x, y, color);
	}
}
