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
// # include "get_next_line.h"
# include "MLX42/MLX42.h"

# include "defines.h"

typedef struct s_game
{
}	t_game;

// Functions

// Parsing
bool	check_input_file(int argc, char * file_path);

// Errors
void	puterror(char *message);
int		puterr_status(char *message, int status);

#endif /* cub3d.h */
