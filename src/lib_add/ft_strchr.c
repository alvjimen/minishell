/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:04:04 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/21 12:23:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s != (unsigned char)c && *s)
		s++;
	if (*(unsigned char *)s != (unsigned char)c)
		return (NULL);
	return ((char *)s);
}
