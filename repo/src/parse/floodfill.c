/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:07:20 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/05 18:07:20 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_flood_arr(t_game *game)
{
	char	**flood_arr;
	int		i;

	flood_arr = malloc(sizeof(char *) * (game->map_height + 1));
	if (!flood_arr)
		return (1);
	i = 0;
	while (i < game->map_height)
	{
		flood_arr[i] = ft_strdup(game->map[i]);
		// TODO: check for failure
		i++;
	}
	return (0);
}

bool	is_surrounded_by_walls(t_game *game)
{
	if (get_flood_arr(game) == 1)
		return (false);
	return (true);
}