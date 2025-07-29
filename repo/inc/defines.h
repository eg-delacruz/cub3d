/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:28:23 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/29 20:11:30 by jtivan-r         ###   ########.fr       */
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

# ifndef PI
#  define PI 3.14159265358979323846
# endif

// For the vector components
# define X 0
# define Y 1
# define COS 0
# define SIN 1

#define SCREEN_W 640
#define SCREEN_H 480
#define TEX_W 64
#define TEX_H 64
#define MAP_W 24
#define MAP_H 24

typedef double	t_dvector[2];
typedef	int		t_ivector[2];
typedef int		**t_map;

typedef enum e_direction
{
	SO,
	NO,
	WE,
	EA
} t_direction;

typedef enum e_key_mov
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LEFT_ROT,
	RIGHT_ROT
}	t_key_mov;

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
	t_dvector	init_dir;
	t_dvector	curr_dir;
	t_dvector	plane;
	t_dvector	screen_pos;
	t_ivector	map_pos;
}	t_player;


typedef struct s_game
{
	mlx_t	*mlx;
	mlx_image_t *image;
	t_player	*player;
	t_map		worldMap;
	int32_t		ceiling_color;
	int32_t		floor_color;
}	t_game;


#endif /* defines.h */
