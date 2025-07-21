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

static void	get_map_from_file(t_game *game, int *file_fd)
{
	(void)game;
	char	*line;

	line = get_next_line(*file_fd);
	while (line)
	{
		if (ft_strnstr_exact(line, "\r\n", 2) || ft_strnstr_exact(line, "\n", 1))
		{
			ft_safe_free((void **)&line);
			line = get_next_line(*file_fd);
			continue ;
		}
	}

	/*
	TODO:
	1. Count remaining lines from here till the end
	1.1. If current line from previous loop is still not EOL (NULL), start the count at/add +1 to the count
	2. Create a struct called parse, to keep all the data that is only needed for the parse. This way, the game struct will only have useful data for the execution. Parse will have to have the char * of the colors, since JP needs them as ints in arrays. It will also have the count of the file size in rows, to be able to keep track of the line where the map starts.
	3. From this point on, I will have to scan the file till the end to know the remaining lines and create the array accordingly. I will also need the total rows of the file to know where I need to reposition the reading to actually copy the map in the array. To know if there are empty spaces between the map and another element after the map (invalid file then), scan the map till the point where the lines are not only "10 NSEW". From there, check the map till the end. If only \n, then the map is correct and I will have to clean those /n later on. If not only \n, throw error and exit program
	*/
}

// TODO: close the fd and reach EOF inside this function
bool	is_valid_map(t_game *game, int *file_fd)
{
	get_map_from_file(game, file_fd);
	return (true);
}