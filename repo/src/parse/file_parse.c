/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:17:52 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/18 11:17:52 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if passed line is a valid file element (except for the map)
static bool	is_valid_eleme_type(char *elem)
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

static int	set_elems_in_arr(char **elems, int *file_fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(*file_fd);
	while (line && i < 6)
	{
		if (ft_strnstr_exact(line, "\r\n", 2)
			|| ft_strnstr_exact(line, "\n", 1))
		{
			ft_safe_free((void **)&line);
			line = get_next_line(*file_fd);
			continue ;
		}
		elems[i] = ft_strtrim(line, "\n\r ");
		if (elems[i] == NULL)
			return (free_elems_arr_at_malloc_err(elems, i), close(*file_fd), 1);
		ft_safe_free((void **)&line);
		line = get_next_line(*file_fd);
		i++;
	}
	ft_safe_free((void **)&line);
	elems[i] = NULL;
	return (0);
}

// Check if map position is right in the file
// Check if elements are the right ones
static bool	valid_map_position_and_elems(char **elems, int *file_fd)
{
	int	i;

	i = 0;
	while (elems[i])
	{
		if (is_valid_eleme_type(elems[i]) == false)
		{
			if (elems[i][0] == '1')
				puterror(ERR_WRONG_POS);
			else
				puterror(ERR_INVALID_ELEMENT);
			// TODO: free array elems here (reuse the free_elems_arr_at_malloc_err function)
			close (*file_fd);
			return (false);
		}
		i++;
	}
	return (true);
}

// TODO: check empty file
int	parse_input_file(t_game *game, char *path)
{
	int		file_fd;
	// TODO: liberar sus elementos pero no el arreglo (está en stack)
	char	*elems[7];

	file_fd = open(path, O_RDONLY);
	if (set_elems_in_arr(elems, &file_fd) == 1)
		return (error_free_status("set_elems_in_arr function failed", game, 1));
	if (valid_map_position_and_elems(elems, &file_fd) == false)
		return (free_game(game), 1);
	// TODO: afterwards, assign each element to the corresponding value in the game struct. If there is already an element assigned to the struct, that would mean that the elements are repeated
	// TODO: careful in case of errors in file to close this where needed
	close (file_fd);
	return (0);
}