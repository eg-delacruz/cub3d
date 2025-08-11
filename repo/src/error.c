/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:14:43 by erde-la-          #+#    #+#             */
/*   Updated: 2025/08/11 16:37:35 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	puterror(char *message)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putendl_fd(RST, 2);
}

//puterror + return a status
int	puterr_status(char *message, int status)
{
	puterror(message);
	return (status);
}

//puterror + free_program + return exit status
int	error_free_status(char *message, t_game *game, int exit_code)
{
	puterror(message);
	free_game(game);
	return (exit_code);
}
