/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:21:10 by jvasquez          #+#    #+#             */
/*   Updated: 2023/03/31 11:50:15 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copy one string array
char	**ft_sarrcpy(char **arr)
{
	int		i;
	char	**new_arr;

	if (!arr)
		return (NULL);
	new_arr = malloc(sizeof(char *) * (ft_sarrsize(arr) + 1));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[i] = NULL;
	return (new_arr);
}
