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
		if (ft_strnstr(&s[count], delim, len_delim))
		{
			index++;
			count += len_delim;
			while (ft_strnstr(&s[count], delim, len_delim))
				count += len_delim;
		}
		else
			count++;
	}
	return (index);
}

static size_t	ft_get_string_size(const char *s, char *delim, size_t nbr )
{
	size_t	size;
	size_t	len_delim;

	size = 0;
	if (!delim)
		return (0);
	len_delim = ft_strlen(delim);
	while (s && s[size])
	{
		if (ft_strnstr(&s[size], delim, ft_strlen(delim)))
			return (size);
		size++;
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

char	**ft_split_chars(char const *s, char *delim)
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
