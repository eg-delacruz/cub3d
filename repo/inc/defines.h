/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:28:23 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/12 21:50:17 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
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
# define ERR_INVALID_MAP_ELEM "Invalid element in the map or after the map"
# define ERR_MAP_DIV "Map divided by linejump or invalid line with spaces"
# define ERR_MAP_SMALL "Map is too small"
# define ERR_ONE_PLAYER "Map must have exactly one player"
# define ERR_TEXTURE_EXT "Textures must be .png images"
# define ERR_NO_TEXTURE "Texture doesn't exists or provided path is invalid"
# define ERR_INVALID_COLOR_1 "RGB color can only have digits"
# define ERR_INVALID_COLOR_2 "RGB color must have exactly 3 byte numbers"
# define ERR_RGB_OUT_OF_RANGE "Each RGB element must be between 0 and 255"

// Function failure because of malloc error messages
# define ERR_INIT_GAME "init_game() function failed"
# define ERR_SET_ELEMS_IN_ARR "set_elems_in_arr() function failed"
# define ERR_CLEAN_MAP "get_clean_map() function failed"
# define ERR_SQUARE_MAP "make_square_map() function failed"
# define ERR_CHECK_COLORS "check_colors() function failed"
# define ERR_REMOVE_EMPTY_SPACES "remove_empty_spaces() function failed"

# ifndef PI
#  define PI 3.14159265358979323846
# endif

// For the vector components
# define X 0
# define Y 1
# define COS 0
# define SIN 1

// Field of View
# define FOV 66

#define SCREEN_W 640
#define SCREEN_H 480
#define TEX_W 64
#define TEX_H 64
#define MAP_W 24
#define MAP_H 24

typedef double	t_dvector[2];
typedef int		t_ivector[2];
typedef int		**t_map;

typedef enum e_direction
{
	SO,
	NO,
	WE,
	EA
}	t_direction;

typedef enum e_key_mov
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LEFT_ROT,
	RIGHT_ROT
}	t_key_mov;

// Structs


/**
 * init_dir: Player initial camera direction when the game starts
 * speed_rot: Camera rotation speed
 * speed_mov: Player movement speed
 * curr_dir: Player current camera direction (after movement)
 * radius: To check if the player can move to the next box
 * FOV: Field of view
 * screen_pos: Player position in the screen
 * map_pos: Player position in the map;
 * plane: Camera plane
 */
typedef struct s_player
{
	double		speed_rot;
	double		speed_mov;
	double		radius;
	double		fov;
	// Estas son posiciones
	t_direction	init_dir; // This is defined as t_dvector init_dir; in JP's part
	t_dvector	curr_dir;
	t_dvector	plane;
	t_ivector	init_pos; // This is called init_map_pos in Jean Paul's part
	t_dvector	pos; // This is called screen_pos in Jean Paul's part
	t_ivector	map_pos;
}	t_player;

typedef struct s_parse
{
	int		file_lines;
	int		map_till_eof_lines;
	char	*file_path;
	// TODO: remember to free these two when parse concludes/when needed
	char	*f_color_str;
	char	*c_color_str;
	char	**raw_map;
	char	**flood_check_map;
}	t_parse;

typedef struct s_game
{
	t_parse			parse;
	struct s_player	*p;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int32_t			c;
	int32_t			f;
	int				map_rows;
	int				map_cols;
	char			**map;
	mlx_t	*mlx;
	mlx_image_t *image;
	t_player	*player;
	t_map		worldMap;
	bool		cursor_blocked;
	int32_t		ceiling_color;
	int32_t		floor_color;
}	t_game;

#endif /* defines.h */
