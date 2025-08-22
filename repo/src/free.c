/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:20:10 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/22 21:42:39 by jtivan-r         ###   ########.fr       */
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
	ft_safe_free((void **)&game->no_tex_path);
	ft_safe_free((void **)&game->so_tex_path);
	ft_safe_free((void **)&game->we_tex_path);
	ft_safe_free((void **)&game->ea_tex_path);
	ft_safe_free((void **)&game->parse.f_color_str);
	ft_safe_free((void **)&game->parse.c_color_str);
	ft_safe_free((void **)&game->p);
	ft_free_split(game->parse.raw_map);
	ft_free_split(game->map);
	ft_free_split(game->parse.flood_check_map);
	mlx_delete_texture(game->no_tex);
	mlx_delete_texture(game->so_tex);
	mlx_delete_texture(game->ea_tex);
	mlx_delete_texture(game->we_tex);
	ft_safe_free((void **)&game);
}
