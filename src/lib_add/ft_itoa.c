/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:41:39 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/22 17:19:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_int_str(int n, int *pos, char *str)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		str[*pos] = '-';
		nb *= -1;
		pos[0]++;
	}
	if (nb > 9)
		ft_int_str(nb / 10, pos, str);
	str[*pos] = nb % 10 + '0';
	pos[0]++;
}

static size_t	lenstr_of_int(int n)
{
	long int	nbr;
	size_t		pos;

	nbr = n;
	pos = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		pos++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		pos++;
	}
	return (++pos);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	int				nbr;

	nbr = 0;
	len = lenstr_of_int(n);
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	ft_int_str(n, &nbr, str);
	return (str);
}
