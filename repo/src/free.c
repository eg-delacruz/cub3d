/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:20:10 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/18 12:20:10 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_elems_arr_at_malloc_err(char **elems, size_t iterator)
{
	while (iterator > 0)
		ft_safe_free((void **)&(elems[--iterator]));
}

void	free_game(t_game *game)
{
	ft_safe_free((void **)&game->no_texture);
	ft_safe_free((void **)&game->so_texture);
	ft_safe_free((void **)&game->we_texture);
	ft_safe_free((void **)&game->ea_texture);
	ft_safe_free((void **)&game->parse.f_color_str);
	ft_safe_free((void **)&game->parse.c_color_str);
	ft_safe_free((void **)&game->p);
	ft_free_split(game->parse.raw_map);
	ft_free_split(game->map);
	ft_free_split(game->parse.flood_check_map);
	ft_safe_free((void **)&game);
}
