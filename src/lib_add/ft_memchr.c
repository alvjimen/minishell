/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:25:44 by alvjimen          #+#    #+#             */
/*   Updated: 2022/07/08 15:06:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	v;

	str = (unsigned char *) s;
	v = (unsigned char) c;
	while (n--)
	{
		if (*str == v)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
