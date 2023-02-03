/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:02:59 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 19:22:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		nbr;
	char		*str;
	char		*src1;

	if (src == dest)
		return (dest);
	src1 = (char *)src;
	str = dest;
	nbr = 0;
	while (nbr < n)
	{
		str[nbr] = src1[nbr];
		nbr++;
	}
	return (dest);
}
