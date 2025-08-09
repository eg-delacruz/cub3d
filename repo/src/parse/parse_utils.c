/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:33:33 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/21 17:33:33 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Intended to avoid leaks in the gnl if EOF isn't reached
void	reach_eof(int	file_fd)
{
	char	*line;

	line = get_next_line(file_fd);
	while (line)
	{
		ft_safe_free((void **)&line);
		line = get_next_line(file_fd);
	}
}

int	get_file_len(char *path)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		ft_safe_free((void **)&line);
		line = get_next_line(fd);
	}
	ft_safe_free((void **)&line);
	close (fd);
	return (count);
}

// Checks if all characters in str are in set
bool	all_chars_in_set(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	bool	found;

	if (!str || !set)
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		found = false;
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				found = true;
				break ;
			}
			j++;
		}
		if (!found)
			return (false);
		i++;
	}
	return (true);
}

//Read file, skipping \n and returning the next content line
char	*get_next_valid_line(int file_fd)
{
	char	*line;

	line = get_next_line(file_fd);
	while (line)
	{
		if (ft_strnstr_exact(line, "\r\n", 2) || ft_strnstr_exact(line, "\n", 1))
		{
			ft_safe_free((void **)&line);
			line = get_next_line(file_fd);
			continue ;
		}
		break ;
	}
	return (line);
}

void	replace_empty_spaces_by_ones(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}
