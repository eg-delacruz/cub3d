/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_file_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:58:53 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/15 22:58:53 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

bool	check_input_file_name(int argc, char *file_path)
{
	int	len;

	if (argc != 2)
	{
		puterror(ERR_INVALID_ARGS);
		return (false);
	}
	len = ft_strlen(file_path);
	if (file_path[len - 4] != '.'
		|| file_path[len - 3] != 'c'
		|| file_path[len - 2] != 'u'
		|| file_path[len - 1] != 'b')
	{
		puterror(ERR_INVALID_FILE_EXT);
		return (false);
	}
	return (true);
}