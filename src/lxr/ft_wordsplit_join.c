/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsplit_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:36:23 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 10:03:38 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	**ft_wordsplit_join_first_regex_star(char **regex, char **old,
		char **words)
{
	regex = ft_sarradd(regex, *old);
	free(*old);
	*old = NULL;
	if (!regex)
		return (ft_wordsplit_join_first_regex_error(regex, words, 1));
	return (regex);
}

static char	**ft_wordsplit_join_first_regex(char **regex, char **old,
		char **words, size_t *counter)
{
	char	*join;

	if (old && *old)
		join = ft_strjoin(*old, words[counter[0]++]);
	else
		join = ft_strjoin("", words[counter[0]++]);
	free(*old);
	*old = NULL;
	if (!join)
		return (ft_wordsplit_join_first_regex_error(regex, words, 2));
	regex = ft_sarradd(regex, join);
	free(join);
	if (!regex)
		ft_sarrfree(&words);
	return (regex);
}

static char	**ft_wordsplit_join_between_first_and_last(char **regex,
		char **words, size_t *counter)
{
	while (words[*counter] && words[*counter + 1])
	{
		regex = ft_sarradd(regex, words[*counter]);
		if (!regex)
		{
			ft_sarrfree(&words);
			return (NULL);
		}
	}
	return (regex);
}

static char	**ft_wordsplit_join_add_last_regex(char **regex, char **words,
		char *str, size_t counter)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str > 1 && str[len_str - 1] == '*')
	{
		regex = ft_sarradd(regex, words[counter]);
		ft_sarrfree(&words);
		return (regex);
	}
	regex = ft_sarradd(regex, words[counter]);
	ft_sarrfree(&words);
	return (regex);
}

char	**ft_wordsplit_join(char **old, char *str, char **regex)
{
	char	**words;
	size_t	counter;

	counter = 0;
	words = ft_split(str, '*');
	if (!words)
		return (ft_wordsplit_join_checks_error(regex, old));
	if (!regex && old && !*old)
		return (words);
	if (*str == '*')
		regex = ft_wordsplit_join_first_regex_star(regex, old, words);
	else
		regex = ft_wordsplit_join_first_regex(regex, old, words, &counter);
	if (!regex)
		return (regex);
	regex = ft_wordsplit_join_between_first_and_last(regex, words, &counter);
	if (!regex)
		return (NULL);
	return (ft_wordsplit_join_add_last_regex(regex, words, str, counter));
}
