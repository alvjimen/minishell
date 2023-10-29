/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:18:16 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 19:31:52 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	nbr;
	int					sig;

	nbr = 0;
	sig = 1;
	while ((*str && *str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str && (*str == 43 || *str == 45))
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
		nbr = (nbr * 10) + (*str++ - 48);
	return (nbr * sig);
}
