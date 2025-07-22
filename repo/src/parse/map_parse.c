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
	/*
	TODO:
	To know if there are empty spaces between the map and another element after the map (invalid file then), scan the map till the point where the lines are not only "10 NSEW". From there, check the map till the end. If only \n, then the map is correct and I will have to clean those /n later on. If not only \n, throw error and exit program
	*/


// TODO: close the fd and reach EOF inside this function
bool	is_valid_map(t_game *game, int file_fd)
{
	if (count_map_lines(game, file_fd) == false)
		return (false);
	if (get_raw_map_arr(game) == 1)
		return (false);
	// ft_put_str_arr(game->parse.raw_map);
	return (true);
}