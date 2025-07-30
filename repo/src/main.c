/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:59:02 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/31 00:13:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t main(int argc, char *args[])
{
	((void)argc, (void)args);
	t_game	game;

	if (!init_mlx(&game))
		return (EXIT_FAILURE);
	(setup_game(&game), setup_hooks(&game));
	int i, j;
	i = 0;
	while (i < MAP_H)
	{
		j = -1;
		while (++j < MAP_W)
			printf("%d ", game.worldMap[i][j]);
		printf("\n");
		i++;
	}
	show_player(game.player);
	raycasting(&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
