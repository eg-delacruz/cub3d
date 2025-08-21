/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:30:56 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/21 23:47:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_player *p, int x)
{
	double	camX;

	camX = 2 * x / (double)SCREEN_W - 1;
	set_dvector(&ray->dir, p->curr_dir[X] + p->plane[X] * camX, \
	p->curr_dir[Y] + p->plane[Y] * camX);
	get_delta_dist(ray);
	get_step_and_side_dist(ray, p);
	ray->hit = 0;
}

// Perform DDA until a wall we find a wall (hit a wall)
void	find_wall(t_ray *ray, t_game *game, t_ivector map_pos)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			map_pos[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			map_pos[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (map_pos[X] < 0 || map_pos[X] >= game->map_cols || map_pos[Y] < 0 || map_pos[Y] >= game->map_rows)
		{
			ray->hit = 1;
			break;
		}
		if (game->map[map_pos[Y]][map_pos[X]] == '1')
			ray->hit = 1;
	}
	get_wall_dir(ray);
	get_perp_wall_dist(ray);
}
