/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:01:33 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/12 21:53:34 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	remove_empty_spaces(char **color)
{
	int		i;
	char	*tmp;

	i = 0;
	while (color[i])
	{
		tmp = ft_strtrim(color[i], " \t");
		if (!tmp)
			return (puterror(ERR_REMOVE_EMPTY_SPACES), 1);
		ft_safe_free((void **)&color[i]);
		color[i] = tmp;
		i++;
	}
	return (0);
}

// Check if each RGB number has only digits
// Check if the RGB number has only three numbers/bytes
static bool	are_valid_symbols(char **color)
{
	int	i;
	int	j;

	if (remove_empty_spaces(color) == 1)
		return (false);
	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (ft_isdigit(color[i][j]) == 0)
				return (puterror(ERR_INVALID_COLOR_1), false);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (puterror(ERR_INVALID_COLOR_2), false);
	return (true);
}

static int	get_rgb_ints(int32_t *dst, char **src)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (src[i])
	{
		rgb[i] = ft_atoi(src[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (puterror(ERR_RGB_OUT_OF_RANGE), 1);
		i++;
	}
	*dst = get_rgba(rgb[0], rgb[1], rgb[2], 255);
	return (0);
}

int	check_colors(t_game *game)
{
	char	**c;
	char	**f;

	c = ft_split(game->parse.c_color_str, ',');
	f = ft_split(game->parse.f_color_str, ',');
	if (c == NULL || f == NULL)
	{
		ft_free_split(c);
		ft_free_split(f);
		return (puterror(ERR_CHECK_COLORS), 1);
	}
	if (!are_valid_symbols(c) || !are_valid_symbols(f))
		return (ft_free_split(c), ft_free_split(f), 1);
	if (get_rgb_ints(&game->c, c) == 1 || get_rgb_ints(&game->f, f) == 1)
		return (ft_free_split(c), ft_free_split(f), 1);
	ft_free_split(c);
	ft_free_split(f);
	return (0);
}
