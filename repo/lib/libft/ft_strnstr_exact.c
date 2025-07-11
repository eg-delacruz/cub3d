/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:29:56 by erde-la-          #+#    #+#             */
/*   Updated: 2025/04/02 11:07:53 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Check if words have exact the same characters and exact same length
//Returns *big if there is a match or NULL
char	*ft_strnstr_exact(const char *big, const char *little, size_t len)
{
	int		big_len;
	int		little_len;
	char	*matching_pointer;

	matching_pointer = ft_strnstr(big, little, len);
	if (matching_pointer)
	{
		big_len = ft_strlen(big);
		little_len = ft_strlen(little);
		if (big_len == little_len)
			return (matching_pointer);
	}
	return (NULL);
}
