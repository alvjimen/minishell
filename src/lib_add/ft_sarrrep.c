/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:25:47 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/05 11:29:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Replace one item at the given index
char	**ft_sarrrep(char **arr, int index, char *str)
{
	int	size;

	size = ft_sarrsize(arr);
	if (size < index || index < 0)
		return (arr);
	free(arr[index]);
	arr[index] = ft_strdup(str);
	if (!arr[index])
		ft_sarrfree(&arr);
	return (arr);
}
