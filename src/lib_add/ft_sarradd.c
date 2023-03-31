/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:41:24 by jvasquez          #+#    #+#             */
/*   Updated: 2023/03/31 12:32:46 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds an item to a string array
char	**ft_sarradd(char **arr, char *string)
{
	int		size;
	char	**new_arr;

	if (!string)
		return (arr);
	size = ft_sarrsize(arr) + 2;
	new_arr = malloc(sizeof(char *) * (size));
	if (!new_arr)
	{
		ft_sarrfree(&arr);
		return (NULL);
	}
	size = 0;
	if (arr)
	{
		/*
		 * This is the same to
			ft_memcpy(arr, new_arr, sizeof(char *) * ft_sarrsize(arr));
		*/
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
