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

static int	set_elems_in_arr(char **elems, int *file_fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(*file_fd);
	while (line && i < 6)
	{
		if (ft_strnstr_exact(line, "\r\n", 2) || ft_strnstr_exact(line, "\n", 1))
		{
			ft_safe_free((void **)&line);
			line = get_next_line(*file_fd);
			continue ;
		}
		elems[i] = ft_strtrim(line, "\n\r ");
		if (elems[i] == NULL)
			return (free_elems_arr_at_malloc_err(elems, i), close(*file_fd), 1);
		ft_safe_free((void **)&line);
		i++;
		if (i < 6)
			line = get_next_line(*file_fd);
	}
	ft_safe_free((void **)&line);
	elems[i] = NULL;
	return (0);
}

// TODO: remember to read the file till the end to avoid leaks of the static variable
int	parse_input_file(t_game *game, char *path)
{
	int		file_fd;
	char	*elems[7];

	file_fd = open(path, O_RDONLY);
	if (is_empty_file(path) == true)
		return (error_free_status(ERR_EMPTY_FILE, game, 1));
	if (set_elems_in_arr(elems, &file_fd) == 1)
		return (error_free_status(ERR_SET_ELEMS_IN_ARR, game, 1));
	if (valid_map_position_and_elems(elems, &file_fd) == false)
		return (free_game(game), 1);
	if (check_duplicate_elems(game, elems, &file_fd) == true)
		return (free_game(game), 1);
	// TODO: checke here the textures
	// TODO: check here the colors
	// Consider to close the fd somewhere else, but here is also not a bad place to do it
	close (file_fd);
	return (0);
}