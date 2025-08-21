/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:56:24 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/22 00:00:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*get_wall_tex(t_game *game, t_direction wall_dir)
{
	if (wall_dir == N)
		return (game->no_tex);
	if (wall_dir == S)
		return (game->so_tex);
	if (wall_dir == W)
		return (game->we_tex);
	if (wall_dir == E)
		return (game->ea_tex);
	return (NULL);
}

static int	get_tex_x(double wall_x, mlx_texture_t *tex)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)tex->width);
	if ((uint32_t)tex_x >= tex->width)
		tex_x = tex->width - 1;
	if (tex_x < 0)
		tex_x = 0;
	return (tex_x);
}

static double	get_wall_x(t_ray *ray, t_player *p)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = p->pos[Y] + ray->perp_wall_dist * ray->dir[Y];
	else
		wall_x = p->pos[X] + ray->perp_wall_dist * ray->dir[X];
	wall_x -= floor(wall_x);
	if (ray->side == 0)
	{
		if (ray->dir[X] > 0)
			wall_x = 1.0 - wall_x;
	}
	else
	{
		if (ray->dir[Y] < 0)
			wall_x = 1.0 - wall_x;
	}
	return (wall_x);
}

void	draw_wall(t_game *game, t_ray *ray, t_wall *wall, int x)
{
	double	wall_x;
	int		tex_x;
	int		y;

	wall_x = get_wall_x(ray, game->p);
	tex_x = get_tex_x(wall_x, wall->tex);
	y = -1;
	while (++y < wall->start)
		mlx_put_pixel(game->image, x, y, game->c);
	draw_ver_line(game, x, wall, tex_x);
	y = wall->end - 1;
	while (++y < SCREEN_H)
		mlx_put_pixel(game->image, x, y, game->f);
}

void	init_wall(t_game *game, t_wall *wall, t_ray *ray)
{
	if (!ray || !wall)
		return ;
	wall->height = (int)(SCREEN_H / fmax(ray->perp_wall_dist, 0.01));
	wall->start = (SCREEN_H / 2) - (wall->height / 2);
	if (wall->start < 0)
		wall->start = 0;
	wall->end = (SCREEN_H / 2) + (wall->height / 2);
	if (wall->end >= SCREEN_H)
		wall->end = SCREEN_H - 1;
	wall->dir = get_wall_dir(ray);
	wall->tex = get_wall_tex(game, wall->dir);
}
