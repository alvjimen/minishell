/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:20:53 by alvjimen          #+#    #+#             */
/*   Updated: 2022/07/09 16:43:17 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	c;
	char	*s;
	char	*d;

	s = (char *)src;
	d = dst;
	c = 0;
	if (!len)
		return (dst);
	if (dst < src)
	{
		while (++c <= len)
			d[c - 1] = s[c - 1];
	}
	else if (dst > src)
	{
		c = len;
		while (--c <= len)
			d[c] = s[c];
	}
	return (dst);
}
