/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:41:24 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/07 22:12:50 by alvjimen         ###   ########.fr       */
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
		ft_memcpy(arr, new_arr, sizeof(char *) * ft_sarrsize(arr));
		ft_sarrfree(&arr);
	}
	new_arr[size - 2] = ft_strdup(string);
	new_arr[size - 1] = NULL;
	return (new_arr);
}
