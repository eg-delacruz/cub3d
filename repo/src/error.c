/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:14:43 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/15 23:14:43 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	puterror(char *message)
{
	ft_putstr_fd(R, 2);
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

// TODO: complete in the future
// //puterror + free_program
// void	error_free(char *message, t_shell *shell, int exit_code)
// {
// 	puterror(message);
// 	free_program(shell);
// 	exit(exit_code);
// }