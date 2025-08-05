/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:47:59 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/24 10:47:59 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	are_valid_map_elements(char **raw_map)
{
	int	i;

	i = 0;
	while (raw_map[i])
	{
		if (all_chars_in_set(raw_map[i], "1 0NSEW\n\r") == false)
		{
			puterror(ERR_INVALID_MAP_ELEM);
			return (false);
		}
		i++;
	}
	return (true);
}

// Check if map is divided by a linejump
// Also, count map heigth
bool	is_map_divided(t_game *game)
{
	char	**raw_map;
	int		i;

	raw_map = game->parse.raw_map;
	i = 0;
	while (raw_map[i])
	{
		if (raw_map[i][0] == '\0' || ft_str_all_same(raw_map[i], ' ') == true)
			break ;
		i++;
	}
	if (i <= 2)
		return (puterror(ERR_MAP_SMALL), true);
	game->map_height = i;
	if (raw_map[i])
	{
		i++;
		while (raw_map[i])
		{
			if (raw_map[i][0] != '\0' || !ft_str_all_same(raw_map[i], ' '))
				return (puterror(ERR_MAP_DIV), true);
			i++;
		}
	}
	return (false);
}

int	get_clean_map(t_game *game)
{
	int	i;

	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (1);
	i = 0;
	while (game->parse.raw_map[i])
	{
		game->map[i] = ft_strdup(game->parse.raw_map[i]);
		if (!game->map[i])
		{
			free_elems_arr_at_malloc_err(game->map, i);
			puterror(ERR_CLEAN_MAP);
			return (1);
		}
		i++;
	}
	game->map[i] = NULL;
	return (0);
}

int	map_valid_dimentions(t_game *game)
{
	int	length;
	int	tmp_length;
	int	i;

	length = 0;
	i = 0;
	while (game->map[i])
	{
		tmp_length = ft_strlen(game->map[i]);
		if (tmp_length > length)
			length = tmp_length;
		i++;
	}
	game->map_length = length;
	if (game->map_height <= 2 || game->map_length <= 2)
	{
		puterror(ERR_MAP_SMALL);
		return (1);
	}
	return (0);
}

// Also gets player position
// TODO: test this
bool	is_exactly_one_player(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' 
				|| game->map[i][j] == 'E'  || game->map[i][j] == 'W')
			{
				count++;
				game->p->init_pos->x = j;
				game->p->init_pos->y = i;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (puterror(ERR_ONE_PLAYER), false);
	return (true);
}