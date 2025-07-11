/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:58:12 by erde-la-          #+#    #+#             */
/*   Updated: 2025/04/20 16:58:12 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**get_arr(t_list *lst)
{
	int		i;
	t_list	*temp;
	char	**arr;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	arr = malloc(sizeof(char *) * (i + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

static void	free_at_failure(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		ft_safe_free((void **)&arr[j]);
		j++;
	}
	ft_safe_free((void **)&arr);
}

//Use only to get an arr from a list with char * content type
char	**ft_lst_to_arr(t_list	*lst)
{
	char	**arr;
	int		i;
	t_list	*tmp;

	arr = get_arr(lst);
	if (!arr)
		return (NULL);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		arr[i] = ft_strdup((char *)(tmp->content));
		if (!arr[i])
		{
			free_at_failure(arr, i);
			return (NULL);
		}
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}
