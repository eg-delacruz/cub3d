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

static bool	floodfill(t_game *game, int p_x, int p_y)
{
	char	**flood_map;
	int		rows;
	char	tile;

	flood_map = game->parse.flood_check_map;
	rows = game->map_rows;
	if (p_x < 0 || p_y < 0	
		|| p_x >= (int)ft_strlen(flood_map[p_y]) || p_y >= rows)
		return (false);
	tile = flood_map[p_y][p_x];
	if (tile == '\0')
		return (false);
	if (tile == '1' || tile == 'x')
		return (true);
	flood_map[p_y][p_x] = 'x';
	return (
		floodfill(game, p_x + 1, p_y) &&
		floodfill(game, p_x - 1, p_y) &&
		floodfill(game, p_x, p_y + 1) &&
		floodfill(game, p_x, p_y - 1)
	);
}

static int get_flood_arr(t_game *game)
{
	char	**flood_arr;
	int		i;

	flood_arr = malloc(sizeof(char *) * (game->map_rows + 1));
	if (!flood_arr)
		return (1);
	i = 0;
	while (i < game->map_rows)
	{
		flood_arr[i] = ft_strdup(game->map[i]);
		if (!flood_arr[i])
		{
			free_elems_arr_at_malloc_err(flood_arr, i);
			ft_safe_free((void **)&flood_arr);
			return (1);
		}
		i++;
	}
	flood_arr[i] = NULL;
	game->parse.flood_check_map = flood_arr;
	return (0);
}

bool	is_surrounded_by_walls(t_game *game)
{
	if (get_flood_arr(game) == 1)
		return (false);
	if (floodfill(game, game->p->init_pos[0], game->p->init_pos[1]) == false)
		return (puterror(ERR_WRONG_MAP_2), false);
	ft_free_split(game->parse.flood_check_map);
	game->parse.flood_check_map = NULL;
	return (true);
}