/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:55:14 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/08 18:55:14 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Make all rows the same length by adding '1's if necessary
int	make_square_map(char **map, int cols)
{
	int		i;
	char	*new_row;
	size_t	remaining_len;

	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < cols)
		{
			new_row = malloc(sizeof(char) * (cols + 1));
			if (!new_row)
				return (puterror(ERR_SQUARE_MAP), 1);
			ft_strlcpy(new_row, map[i], cols + 1);
			remaining_len = cols - ft_strlen(map[i]);
			ft_memset(new_row + ft_strlen(map[i]), '1', remaining_len);
			new_row[cols] = '\0';
			ft_safe_free((void **)&map[i]);
			map[i] = new_row;
		}
		i++;
	}
	return (0);
}

void	store_init_player_dir(t_game *game)
{
	char	dir;

	dir = game->map[game->p->init_pos[1]][game->p->init_pos[0]];
	if (dir == 'N')
		game->p->init_dir = NO;
	else if (dir == 'S')
		game->p->init_dir = SO;
	else if (dir == 'W')
		game->p->init_dir = WE;
	else if (dir == 'E')
		game->p->init_dir = EA;
	else
		return ;
	game->map[game->p->init_pos[1]][game->p->init_pos[0]] = '0';
}
