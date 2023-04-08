/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrmerge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:07:35 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/08 15:27:44 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sarr.h"

char	**ft_sarrmerge(char **arr, char **arr_merge, int index)
{
	size_t	i;
	size_t	j;
	char	**new_arr;

	if (!arr || ! arr_merge)
	{
		ft_sarrfree(&arr);
		ft_sarrfree(&arr_merge);
		return (NULL);
	}
	i = 0;
	while (arr[i] && i < index)
	{
		new_arr = ft_sarradd(arr[i]);
		if (new_arr == NULL)
		{
			ft_sarrfree(&arr);
			ft_sarrfree(&arr_merge);
			return (NULL);
		}
		i++;
	}
	j = 0;
	while (arr_merge[j])
	{
		new_arr = ft_sarradd(arr_merge[j]);
		if (new_arr == NULL)
		{
			ft_sarrfree(&arr);
			ft_sarrfree(&arr_merge);
			return (NULL);
		}
		j++;
	}
	while (arr[i])
	{
		new_arr = ft_sarradd(arr[i]);
		if (new_arr == NULL)
		{
			ft_sarrfree(&arr);
			ft_sarrfree(&arr_merge);
			return (NULL);
		}
		i++;
	}
	return (new_arr);
}
