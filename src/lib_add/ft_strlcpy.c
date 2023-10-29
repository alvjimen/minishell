/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:15:10 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/28 13:07:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	int		len;

	count = 0;
	len = 0;
	while (src[len])
		len++;
	if (dstsize > 0)
	{
		while (src[count] && (count < (dstsize - 1)))
		{
			dst[count] = src[count];
			count++;
		}
	dst[count] = '\0';
	}
	return (len);
}
