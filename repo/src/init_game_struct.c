/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:55:34 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/18 10:55:34 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

t_game *init_game_struct(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}