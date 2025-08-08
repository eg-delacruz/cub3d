/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:28:23 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/15 23:28:23 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//Colors
# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define M "\033[35m"
# define C "\033[36m"
# define W "\033[37m"
# define BGR "\033[41;37m"
# define BGC "\033[46;37m"
# define BGG "\033[42;37m"
# define BGY "\033[43;37m"
# define BGM "\033[45;37m"
# define BGB "\033[44;37m"
# define RST "\033[0m"

// Error messages
# define ERR_INVALID_ARGS "Exactly one argument expected (.cub file path)"
# define ERR_INVALID_FILE_EXT "Invalid file extention (.cub)"
# define ERR_FILE_DOESNT_EXIST "Provided file doesn't exist"
# define ERR_WRONG_POS "Wrong map position or missing element in .cub file"
# define ERR_INVALID_ELEMENT "Invalid element. Expected: NO, SO, WE, EA, F, C"
# define ERR_EMPTY_FILE "The provided .cub file is empty"
# define ERR_MISSING_ELEMS "Missing elements in file"
# define ERR_DUPL_ELEM "One or more elements duplicated in .cub file"
# define ERR_NO_MAP "No map provided in the .cub file"
# define ERR_ELEMS_BEFORE_MAP "Only newlines allowed between elements and map"
# define ERR_WRONG_MAP_1 "Invalid element before map or invalid map"
# define ERR_WRONG_MAP_2 "Player is not enclosed by walls in the map"
# define ERR_INVALID_MAP_ELEM "Invalid element in the map or after ther map"
# define ERR_MAP_DIV "Map divided by linejump or invalid line with spaces"
# define ERR_MAP_SMALL "Map is too small"
# define ERR_ONE_PLAYER "Map must have exactly one player"

// Function failure because of malloc error messages
# define ERR_SET_ELEMS_IN_ARR "set_elems_in_arr() function failed"
# define ERR_CLEAN_MAP "get_clean_map() function failed"
# define ERR_SQUARE_MAP "make_square_map() function failed"

# ifndef PI
#  define PI 3.14159265358979323846
# endif

typedef double	t_dvector[2];
typedef	int		t_ivector[2];

typedef enum e_direction
{
	SO,
	NO,
	WE,
	EA
} t_direction;

// Structs

typedef struct s_player
{
	double		speed_rot;
	double		speed_mov;
	double		radius;
	double		fov;
	// Estas son posiciones
	char		init_dir; // This is defined as t_dvector init_dir; in JP's part
	t_dvector	curr_dir;
	t_dvector	plane;
	t_ivector	init_pos; // This is called init_map_pos in Jean Paul's part
	t_dvector	pos; // This is called screen_pos in Jean Paul's part
}	t_player;

typedef struct s_parse
{
	int		file_lines;
	int		map_till_eof_lines;
	char	*file_path;
	// TODO: remember to free these two when parse concludes/when needed
	char 	*F_color_str;
	char 	*C_color_str;
	char	**raw_map;
	char	**flood_check_map;
}	t_parse;

typedef struct s_game
{
	t_parse			parse;
	struct s_player	*p;
	char			*NO_texture;
	char			*SO_texture;
	char			*WE_texture;
	char			*EA_texture;
	int				map_rows;
	int				map_cols;
	char			**map;
}	t_game;

#endif /* defines.h */
