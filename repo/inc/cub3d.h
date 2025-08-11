/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:28:28 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/11 17:17:03 by jtivan-r         ###   ########.fr       */
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

// typedef struct s_game
// {
// }	t_game;

// Functions
t_game	*init_program_struct(void);

// Parsing
bool	check_input_file(int argc, char *file_path);
int		parse_input_file(t_game *game, char *path);
bool	is_empty_file(char *path);
int		get_file_len(char *path);
bool	valid_map_position_and_elems(char **elems, int file_fd);
bool	check_duplicate_elems(t_game *game, char **elems, int fd);
void	reach_eof(int file_fd);
bool	is_valid_map(t_game *game, int file_fd);
char	*get_next_valid_line(int file_fd);
bool	all_chars_in_set(const char *str, const char *set);
bool	are_valid_map_elements(char **raw_map);
bool	is_map_divided(t_game *game);
int		get_clean_map(t_game *game);
int		map_valid_dimentions(t_game *game);
bool	is_exactly_one_player(t_game *game);
bool	is_surrounded_by_walls(t_game *game);
void	replace_empty_spaces_by_ones(char **map);
int		make_square_map(char **map, int cols);
void	store_init_player_dir(t_game *game);
int		check_textures(t_game *game);
int		check_colors(t_game *game);
bool		check_input_file_name(int argc, char * file_path);

// Errors
void		puterror(char *message);
int			puterr_status(char *message, int status);

// Game graphics
void 		raycasting(t_game *game);
void		draw_ver_line(t_game *game, int x, int start, int end, int32_t color);

// Game utils
bool		init_mlx(t_game	*game);
int			**create_map(void);
t_player	*init_player2(t_direction init_dir);
void		setup_game(t_game *game);

// Vector utils
void		rotate_dvector(t_dvector *vec, double rot);
void		set_dvector(t_dvector *vec, double x, double y);
void		set_ivector(t_ivector *vec, int x, int y);

// Colors
int32_t		get_rgba(int32_t r, int32_t g, int32_t b, int32_t a);
int32_t		get_r(int32_t rgba);
int32_t		get_g(int32_t rgba);
int32_t		get_b(int32_t rgba);
int32_t		get_a(int32_t rgba);


// Player movement and rotation
void 		rotate_player(t_game *game, t_key_mov key);
void 		move_player(t_game *game, t_key_mov key);
void 		strafe_player(t_game *game, t_key_mov key);

// Player utils
bool 		is_wall_collision(t_map map, double y, double x, double radius);
void		show_player(t_player *player);
void		set_player_dir(t_player	*player, t_direction init_dir);

// Hooks
void		setup_hooks(t_game *game);
void	puterror(char *message);
int		puterr_status(char *message, int status);
int		error_free_status(char *message, t_game *game, int exit_code);

// Free
void	free_elems_arr_at_malloc_err(char **elems, size_t iterator);
void	free_game(t_game *game);

#endif /* cub3d.h */
