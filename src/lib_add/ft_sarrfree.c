/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:48:58 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/19 12:04:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sarrfree(char ***arr)
{
	int	i;

	if (!arr || !arr[0])
		return ;
	i = -1;
	while (arr[0][++i])
	{
		if (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = NULL;
		}
	}
	free (*arr);
	*arr = NULL;
}
