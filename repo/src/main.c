/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:59:02 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/22 21:14:39 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (!setup_game(game))
		return (EXIT_FAILURE);
	raycasting(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
