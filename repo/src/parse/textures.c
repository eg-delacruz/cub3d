/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:01:02 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/15 16:04:41 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check the .png extention and if the file exists
static bool	is_valid_texture(char *path)
{
	int	len;
	int	fd;

	if (!path)
		return (false);
	len = ft_strlen(path);
	if (len < 4 || path[len - 4] != '.'
		|| path[len - 3] != 'p'
		|| path[len - 2] != 'n'
		|| path[len - 1] != 'g')
	{
		puterror(ERR_TEXTURE_EXT);
		return (false);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		puterror(ERR_NO_TEXTURE);
		return (false);
	}
	close(fd);
	return (true);
}

int	check_textures(t_game *game)
{
	if (!is_valid_texture(game->no_tex_path)
		|| !is_valid_texture(game->so_tex_path)
		|| !is_valid_texture(game->we_tex_path)
		|| !is_valid_texture(game->ea_tex_path))
		return (1);
	return (0);
}

bool	load_textures(t_game *game)
{
	game->ea_tex = mlx_load_png(game->ea_tex_path);
	if (!game->ea_tex)
		return (false);
	game->we_tex = mlx_load_png(game->we_tex_path);
	if (!game->we_tex)
		return (false);
	game->no_tex = mlx_load_png(game->no_tex_path);
	if (!game->no_tex)
		return (false);
	game->so_tex = mlx_load_png(game->so_tex_path);
	if (!game->so_tex)
		return (false);
	return (true);
}
