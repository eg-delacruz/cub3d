/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:28:28 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/15 23:28:28 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"

# include "defines.h"

typedef struct s_game
{
	char *NO_texture;
	char *SO_texture;
	char *WE_texture;
	char *EA_texture;
	char *F_color_str;
	char *C_color_str;
}	t_game;

// Functions
t_game	*init_game_struct(void);

// Parsing
bool	check_input_file(int argc, char *file_path);
int		parse_input_file(t_game *game, char *path);
bool	is_empty_file(char *path);
bool	valid_map_position_and_elems(char **elems, int *file_fd);
bool	check_duplicate_elems(t_game *game, char **elems, int *file_fd);
void	reach_EOF(int	*file_fd);

// Errors
void	puterror(char *message);
int		puterr_status(char *message, int status);
int		error_free_status(char *message, t_game *game, int exit_code);

// Free
void	free_elems_arr_at_malloc_err(char **elems, size_t iterator);
void	free_game(t_game *game);

#endif /* cub3d.h */
