/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:28:23 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/15 23:28:23 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

//Colors
# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define M "\033[35m"
# define C "\033[36m"
# define W "\033[37m"
# define BGR "\033[41;37m"
# define BGC "\033[46;37m"
# define BGG "\033[42;37m"
# define BGY "\033[43;37m"
# define BGM "\033[45;37m"
# define BGB "\033[44;37m"
# define RST "\033[0m"

// Error messages
# define ERR_INVALID_ARGS "Exactly one argument expected (.cub file path)"
# define ERR_INVALID_FILE_EXT "Invalid file extention (.cub)"
# define ERR_FILE_DOESNT_EXIST "Provided file doesn't exist"
# define ERR_WRONG_POS "Wrong map position or missing element in .cub file"
# define ERR_INVALID_ELEMENT "Invalid element. Expected: NO, SO, WE, EA, F, C"

# ifndef PI
#  define PI 3.14159265358979323846
# endif

#endif /* defines.h */
