/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:37:17 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/15 15:52:42 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if passed line is a valid file element (except for the map)
static bool	is_valid_elem_type(char *elem)
{
	if (!elem)
		return (false);
	if (ft_strnstr(elem, "NO", 2))
		return (true);
	else if (ft_strnstr(elem, "SO", 2))
		return (true);
	else if (ft_strnstr(elem, "WE", 2))
		return (true);
	else if (ft_strnstr(elem, "EA", 2))
		return (true);
	else if (ft_strnstr(elem, "F", 2))
		return (true);
	else if (ft_strnstr(elem, "C", 2))
		return (true);
	else
		return (false);
}

bool	is_empty_file(char *path)
{
	int		file_fd;
	char	buffer;

	file_fd = open(path, O_RDONLY);
	if (read(file_fd, &buffer, 1) == 0)
	{
		close(file_fd);
		return (true);
	}
	close(file_fd);
	return (false);
}

// Check if map position is right in the file
// Check if elements are the right ones
// Check if file has exactly 6 elements
bool	valid_map_position_and_elems(char **elems, int file_fd)
{
	int	i;

	i = 0;
	while (elems[i])
	{
		if (is_valid_elem_type(elems[i]) == false)
		{
			if (elems[i][0] == '1')
				puterror(ERR_WRONG_POS);
			else
				puterror(ERR_INVALID_ELEMENT);
			reach_eof(file_fd);
			close (file_fd);
			free_elems_arr_at_malloc_err(elems, 6);
			return (false);
		}
		i++;
	}
	if (i != 6)
	{
		free_elems_arr_at_malloc_err(elems, 6);
		puterror(ERR_MISSING_ELEMS);
		return (reach_eof(file_fd), close (file_fd), false);
	}
	return (true);
}

// Returns true if there is at least one element duplicated
// Fill the t_game struct with the elems if everything right
bool	check_duplicate_elems(t_game *game, char **elems, int fd)
{
	int	i;

	i = -1;
	while (elems[++i])
	{
		if (ft_strnstr(elems[i], "NO", 2) && !game->no_tex_path)
			game->no_tex_path = ft_strtrim((elems[i] + 2), " \t");
		else if (ft_strnstr(elems[i], "SO", 2) && !game->so_tex_path)
			game->so_tex_path = ft_strtrim((elems[i] + 2), " \t");
		else if (ft_strnstr(elems[i], "WE", 2) && !game->we_tex_path)
			game->we_tex_path = ft_strtrim((elems[i] + 2), " \t");
		else if (ft_strnstr(elems[i], "EA", 2) && !game->ea_tex_path)
			game->ea_tex_path = ft_strtrim((elems[i] + 2), " \t");
		else if (ft_strnstr(elems[i], "F", 1) && !game->parse.f_color_str)
			game->parse.f_color_str = ft_strtrim((elems[i] + 1), " \t");
		else if (ft_strnstr(elems[i], "C", 1) && !game->parse.c_color_str)
			game->parse.c_color_str = ft_strtrim((elems[i] + 1), " \t");
		else
		{
			free_elems_arr_at_malloc_err(elems, 6);
			return (reach_eof(fd), close(fd), puterror(ERR_DUPL_ELEM), true);
		}
	}
	free_elems_arr_at_malloc_err(elems, 6);
	return (false);
}
