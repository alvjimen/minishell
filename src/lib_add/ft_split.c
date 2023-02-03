/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:36:36 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/30 14:38:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_index(const char *s, char delim)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	while (s && s[count])
	{
		if (s[count] != delim)
		{
			index++;
			while (s[count] != delim && s[count])
				count++;
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

static	char	**ft_clear_words(char **words, size_t len)
{
	size_t	index;

	index = len + 1;
	while (index <= 0)
	{
		free(words[index]);
		index--;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	index;
	size_t	index_len;
	size_t	count;
	size_t	wordsize;

	if (!s)
		return (NULL);
	index = -1;
	index_len = ft_count_index(s, c);
	count = 0;
	words = (char **)ft_calloc(sizeof(char *), index_len + 1);
	if (!words)
		return (NULL);
	while (++index < index_len)
	{
		while (s[count] == c)
			count++;
		wordsize = ft_get_string_size(s, c, count);
		words[index] = ft_substr(s, count, wordsize);
		if (words[index] == NULL)
			return (ft_clear_words(words, index_len));
		count += wordsize;
	}
	return (words);
}
