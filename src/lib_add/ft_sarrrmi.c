/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrrmi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:23:02 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/05 11:32:57 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Remove one item given an index
char	**ft_sarrrmi(int index, char **arr)
{
	int		i;
	int		j;
	char	**new_arr;

	i = ft_sarrsize(arr);
	if (index > i || index < 0)
		return (arr);
	new_arr = malloc(sizeof(char *) * (i));
	if (!new_arr)
	{
		ft_sarrfree(&arr);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (arr[++i])
	{
		if (i != index)
		{
			new_arr[j++] = ft_strdup(arr[i]);
			if (new_arr[j - 1] == NULL)
			{
				ft_sarrfree(&new_arr);
				return (NULL);
			}
		}
	}
	new_arr[j] = NULL;
	ft_sarrfree(&arr);
	return (new_arr);
}
