/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:59:02 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/11 17:28:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/MLX42.h"


int32_t	main(int argc, char *args[])
{
	t_game	*game;

	if (!check_input_file(argc, args[1]))
		return (EXIT_FAILURE);
	game = init_program_struct();
	if (!game)
		return (EXIT_FAILURE);
	if (parse_input_file(game, args[1]) == 1)
		return (EXIT_FAILURE);
	if (!init_mlx(game))
		return (EXIT_FAILURE);
	(setup_game(game), setup_hooks(game));
	show_player(game->player);
	raycasting(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
