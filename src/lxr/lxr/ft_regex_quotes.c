/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:04:41 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 09:44:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static void	ft_regex_quotes_set(char **old, char **join, char ***regex,
		size_t *counter)
{
	*old = NULL;
	*join = NULL;
	*regex = NULL;
	*counter = 0;
}

static char	**ft_regex_quotes_check(t_quotes *quote, int *quoted_last)
{
	*quoted_last = !ft_char_quotes(quote->last_unquote[0]);
	if (ft_quotes_unquoting(quote) == FAILURE)
		return (NULL);
	return ((char **)quote);
}

static char	**ft_check_post_loop(t_quotes *quote, char ***regex, char **old,
		size_t counter)
{
	if (!quote->last_unquote)
	{
		*regex = ft_sarradd(*regex, *old);
		free(*old);
		return (*regex);
	}
	if (!*old && counter)
	{
		ft_sarrfree(regex);
		return (NULL);
	}
	return ((char **)quote);
}

static char	**ft_regex_quotes_last_unquote(int quoted_last, t_quotes *quote,
		char ***regex, char **old)
{
	char	*join;

	join = NULL;
	if (quoted_last && ft_strchr(quote->last_unquote, '*'))
		*regex = ft_wordsplit_join(old, quote->last_unquote, *regex);
	else
	{
		ft_join_(*old, quote->last_unquote, &join);
		free(*old);
		if (!join)
		{
			ft_sarrfree(regex);
			return (NULL);
		}
		*regex = ft_sarradd(*regex, join);
		free(join);
	}
	return (*regex);
}

char	**ft_regex_quotes(t_quotes *quote)
{
	char	**regex;
	char	*join;
	char	*old;
	size_t	counter;
	int		quoted_last;

	if (!quote)
		return (NULL);
	ft_regex_quotes_set(&old, &join, &regex, &counter);
	if (ft_regex_quotes_check(quote, &quoted_last) == NULL)
		return (NULL);
	ft_regex_quotes_loop(quote, &regex, &old, &counter);
	join = (char *)ft_check_post_loop(quote, &regex, &old, counter);
	if (join != (char *)quote)
		return ((char **)join);
	join = (char *)ft_regex_quotes_last_unquote(quoted_last, quote,
			&regex, &old);
	if (!join)
		return ((char **)join);
	return (regex);
}
