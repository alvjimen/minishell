/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:39:26 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 19:48:55 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*store;
	char	*query;
	size_t	c_s;
	size_t	c_q;

	store = (char *) haystack;
	query = (char *) needle;
	c_s = 0;
	c_q = 0;
	if (*query == 0)
		return (store);
	while (store[c_s] && c_s < len)
	{
		while (store[c_s + c_q] == query[c_q] && (c_q + c_s) < len)
		{
			if (query[c_q + 1] == 0)
				return (&(store[c_s]));
			c_q++;
		}
		if (store[c_s] != query[c_q] && query[c_q] && c_q != 0)
			c_q = 0;
		c_s++;
	}
	return (NULL);
}
