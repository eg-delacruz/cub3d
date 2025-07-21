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

# include "cub3d.h"

// Intended to avoid leaks in the gnl if EOF isn't reached
void	reach_EOF(int	*file_fd)
{
	char	*line;

	line = get_next_line(*file_fd);
	while (line)
	{
		ft_safe_free((void **)&line);
		line = get_next_line(*file_fd);
	}
}