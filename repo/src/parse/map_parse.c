/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:27:59 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/21 17:27:59 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// Returns false if ther is something wrong with map
static bool	count_map_lines(t_game *game, int file_fd)
{
	char	*line;

	line = get_next_valid_line(file_fd);
	if (line == NULL)
		return (puterror(ERR_NO_MAP), false);
	if (all_chars_in_set(line, " \n\r") == true
		|| all_chars_in_set(line, " \n") == true)
		return (puterror(ERR_ELEMS_BEFORE_MAP), false);
	if (all_chars_in_set(line, "1 \n\r") == false)
		return (puterror(ERR_WRONG_MAP_1), false);
	while (line)
	{
		game->parse.map_till_eof_lines++;
		ft_safe_free((void **)&line);
		line = get_next_line(file_fd);
	}
	close (file_fd);
	return (true);
}

static void	skip_previos_map_lines(int fd, t_game *game)
{
	char	*line;
	int		i;
	int		first_map_line_pos;

	line = get_next_line(fd);
	i = 0;
	first_map_line_pos = game->parse.file_lines - game->parse.map_till_eof_lines;
	while (line && i < (first_map_line_pos - 1))
	{
		ft_safe_free((void **)&line);
		line = get_next_line(fd);
		i++;
	}
	ft_safe_free((void **)&line);
}

static int	get_raw_map_arr(t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	int		map_height;

	fd = open(game->parse.file_path, O_RDONLY);
	skip_previos_map_lines(fd, game);
	map_height = game->parse.map_till_eof_lines;
	game->parse.raw_map = malloc(sizeof(char *) * (map_height + 1));
	if (!game->parse.raw_map)
		return (1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->parse.raw_map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->parse.raw_map[i] = NULL;
	close (fd);
	return (0);
}

static void	clean_line_jumps(t_parse parse)
{
	char	*clean_str;
	int		i;
	size_t	len;

	i = 0;
	while (parse.raw_map[i])
	{
		len = 0;
		while (parse.raw_map[i][len]
			&& parse.raw_map[i][len] != '\n'
			&& parse.raw_map[i][len] != '\r')
			len++;
		clean_str = ft_substr(parse.raw_map[i], 0, len);
		ft_safe_free((void **)&parse.raw_map[i]);
		parse.raw_map[i] = clean_str;
		i++;
	}
}

bool	is_valid_map(t_game *game, int file_fd)
{
	if (count_map_lines(game, file_fd) == false)
		return (false);
	if (get_raw_map_arr(game) == 1)
		return (false);
	if (are_valid_map_elements(game->parse.raw_map) == false)
		return (false);
	clean_line_jumps(game->parse);
	if (is_map_divided(game) == true)
		return (false);
	if (get_clean_map(game) == 1)
		return (false);
	if (map_valid_dimentions(game) == 1)
		return (false);
	// ft_put_str_arr(game->map);
	// Check map_valid length
	// Change all empty spaces by 00 here? Or after floodfill?
	return (true);
}

// static bool	is_map_clean()
// {
// 	/*
// 		TODO:

// 		5. At some point, get map height and length (length == longest line) -> Thinner lines should get ceros at the end to make the map rectangle
// 	*/
// }
