/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:41:24 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/19 12:02:54 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sarradd(char **arr, char *string)
{
	int		size;
	char	**new_arr;

	if (!string)
		return (arr);
	new_arr = malloc(sizeof(char *) * (ft_sarrsize(arr) + 2));
	if (!new_arr)
	{
		ft_sarrfree(&arr);
		return (NULL);
	}
	size = 0;
	if (arr)
	{
		while (arr[size])
		{
			new_arr[size] = ft_strdup(arr[size]);
			size++;
		}
		ft_sarrfree(&arr);
	}
	new_arr[size++] = ft_strdup(string);
	new_arr[size] = NULL;
	return (new_arr);
}
