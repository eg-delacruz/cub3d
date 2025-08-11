/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:01:02 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/09 16:01:02 by erde-la-         ###   ########.fr       */
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
	if (path[len - 4] != '.'
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
		close(fd);
		puterror(ERR_NO_TEXTURE);
		return (false);
	}
	close(fd);
	return (true);
}

int	check_textures(t_game *game)
{
	if (!is_valid_texture(game->no_texture)
		|| !is_valid_texture(game->so_texture)
		|| !is_valid_texture(game->we_texture)
		|| !is_valid_texture(game->ea_texture))
		return (1);
	return (0);
}
