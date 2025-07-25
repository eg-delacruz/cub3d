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
