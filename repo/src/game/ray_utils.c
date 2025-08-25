/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:36:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/25 15:31:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_delta_dist(t_ray *ray)
{
	if (ray->dir[X] == 0)
		ray->delta_dist[X] = 1e30;
	else
		ray->delta_dist[X] = fabs(1 / ray->dir[X]);
	if (ray->dir[Y] == 0)
		ray->delta_dist[Y] = 1e30;
	else
		ray->delta_dist[Y] = fabs(1 / ray->dir[Y]);
}

void	get_step_and_side_dist(t_ray *ray, t_player *p)
{
	if (ray->dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (p->pos[X] - p->map_pos[X]) * ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = (p->map_pos[X] + 1 - p->pos[X]) * \
ray->delta_dist[X];
	}
	if (ray->dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (p->pos[Y] - p->map_pos[Y]) * ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = (p->map_pos[Y] + 1 - p->pos[Y]) * \
ray->delta_dist[Y];
	}
}

t_direction	get_wall_dir(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir[X] > 0)
			return (W);
		else
			return (E);
	}
	else
	{
		if (ray->dir[Y] > 0)
			return (N);
		else
			return (S);
	}
	return (N);
}

void	get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist[X] - ray->delta_dist[X];
	else
		ray->perp_wall_dist = ray->side_dist[Y] - ray->delta_dist[Y];
}
