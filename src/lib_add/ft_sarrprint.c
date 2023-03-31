/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:41:53 by jvasquez          #+#    #+#             */
/*   Updated: 2023/03/31 12:07:55 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Prints the entire array
int	ft_sarrprint(char **arr)
{
	int	i;

	if (!arr || !arr[0])
		return (0);
	i = -1;
	while (arr[++i])
	{
		ft_putstr_fd(arr[i], 1);
		ft_putstr_fd("\n", 1);
	}
	return (i);
}
