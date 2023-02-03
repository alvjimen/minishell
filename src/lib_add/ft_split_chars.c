/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:59:48 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/03 19:24:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_index(const char *s, char *delim)
{
	size_t	count;
	size_t	index;
	size_t	len_delim;

	count = 0;
	index = 0;
	if (!delim)
		return (0);
	len_delim = ft_strlen(delim);
	while (s && s[count])
	{
		if (ft_strnstr(s[count], delim, ft_strlen(delim)))
		{
			index++;
			count += len_delim;
			while (ft_strnstr(s[count], delim, ft_strlen(delim)))
				count += len_delim;
		}
		else
			count++;
	}
	return (index);
}

static size_t	ft_get_string_size(const char *s, char delim, size_t nbr )
{
	size_t	size;

	size = 0;
	while (s[nbr] && s[nbr] != delim)
	{
		size++;
		nbr++;
	}
	return (size);
}
