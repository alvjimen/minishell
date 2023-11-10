/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrrmi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:23:02 by jvasquez          #+#    #+#             */
/*   Updated: 2023/11/10 17:21:30 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean_exit(char **arr, char **arr2)
{
	if (arr)
		ft_sarrfree(&arr);
	if (arr2)
		ft_sarrfree(&arr2);
	return (NULL);
}

char	**ft_sarrrmi(int index, char **arr)
{
	int		i;
	int		j;
	char	**new_arr;

	i = ft_sarrsize(arr);
	if (index > i || index < 0)
		return (arr);
	new_arr = malloc(sizeof(char *) * (i));
	if (!new_arr || (!index && i == 1))
		return (free(new_arr), ft_clean_exit(arr, NULL));
	i = -1;
	j = 0;
	while (arr[++i])
	{
		if (i == index)
			continue ;
		new_arr[j] = ft_strdup(arr[i]);
		if (new_arr[j++] == NULL)
			return (ft_clean_exit(arr, new_arr));
	}
	new_arr[j] = NULL;
	if (arr)
		ft_sarrfree(&arr);
	return (new_arr);
}
