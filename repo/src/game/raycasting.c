/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:43:41 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/08/22 00:13:59 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int			x;
	t_ray		ray;
	t_ivector	map_pos;
	t_wall		wall;

	x = -1;
	ft_memset(game->image->pixels, 255, game->image->width * \
game->image->height * sizeof(int32_t));
	while (++x < SCREEN_W)
	{
		init_ray(&ray, game->p, x);
		set_ivector(&map_pos, game->p->map_pos[X], game->p->map_pos[Y]);
		find_wall(&ray, game, map_pos);
		init_wall(game, &wall, &ray);
		draw_wall(game, &ray, &wall, x);
	}
}
