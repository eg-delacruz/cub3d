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

# include "cub3d.h"

void	free_elems_arr_at_malloc_err(char **elems, size_t iterator)
{
	while (iterator > 0)
		ft_safe_free((void **)&(elems[--iterator]));
}

void	free_game(t_game *game)
{
	ft_safe_free((void **)&game->NO_texture);
	ft_safe_free((void **)&game->SO_texture);
	ft_safe_free((void **)&game->WE_texture);
	ft_safe_free((void **)&game->EA_texture);
	ft_safe_free((void **)&game->F_color);
	ft_safe_free((void **)&game->C_color);
	ft_safe_free((void **)&game);
}