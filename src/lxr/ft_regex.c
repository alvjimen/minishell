/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:26:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:32:34 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*call this after de token analizer after the var expansion*/

char	*ft_interstar(char **split, size_t *counter, char *matched)
{
	while (split[*counter] && split[*counter + 1])
	{
		matched = ft_strnstr(matched, split[*counter], -1);
		if (!matched)
			return (NULL);
		matched += ft_strlen(split[*counter]);
		counter[0]++;
	}	
	return (matched);
}

int	ft_end_star(char *matched, char *str, char **split)
{
	split = NULL;
	if (!str)
		return (SUCCESS);
	matched = ft_strnstr(matched, str, -1);
	if (!matched)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_end_notstar(char *matched, char *str, char ***split,
		char *matched_copy)
{
	size_t	len_split;
	size_t	len;
	size_t	counter;

	if (!str)
		return (FAILURE);
	len_split = ft_strlen(str);
	len = ft_strlen(matched_copy);
	if (len < len_split || matched > &matched_copy[len - len_split])
	{
		ft_sarrfree(split);
		return (FAILURE);
	}
	matched = matched_copy + (len - len_split);
	if (!ft_strnstr(matched, str, -1))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_splitted_regex(char ***split, char *matched, char *regex)
{
	size_t	len;
	size_t	counter;
	char	*matched_copy;

	counter = 0;
	len = 0;
	matched_copy = matched;
	if (!split || !*split || !matched || ((*regex == '.' && *matched != '.')
			|| (*regex != '.' && *matched == '.')))
		return (FAILURE);
	if (*regex != '*'
		&& !ft_start_notstar(&matched, split[0][counter], &counter))
		return (FAILURE);
	else if (*regex == '*' && ft_just_asterisk(split[0][counter]) == SUCCESS)
		return (SUCCESS);
	matched = ft_interstar(split[0], &counter, matched);
	if (!matched)
		return (FAILURE);
	len = ft_strlen(regex);
	if (regex[len - 1] == '*')
		return (ft_end_star(matched, split[0][counter], split[0]) == FAILURE);
	return (ft_end_notstar(matched, split[0][counter], split, matched_copy));
}

int	ft_regex_bash(char ***regex, char *matched, char *str)
{
	size_t	len_r;
	size_t	len_m;

	if (!regex || !*regex || !matched)
		return (FAILURE);
	if (ft_splitted_regex(regex, matched, str) == SUCCESS)
	{
		len_m = ft_strlen(matched);
		if (len_m > 0)
			len_m -= 1;
		len_r = ft_strlen(str);
		if (len_r > 0)
			len_r -= 1;
		if ((str[len_r] != '/' && matched[len_m] != '/')
			|| (str[len_r] == '/' && matched[len_m] == '/'))
			return (SUCCESS);
	}
	return (FAILURE);
}

char	**ft_regex_fail(t_quotes *quotes, char *str, char ***ls)
{
	str = ft_join_quotes(quotes);
	if (!str)
	{
		ft_sarrfree(ls);
		ft_destroy_quotes(&quotes);
		return (NULL);
	}
	*ls = ft_sarradd(*ls, str);
	free(str);
	if (!*ls)
	{
		ft_destroy_quotes(&quotes);
		return (NULL);
	}
	return (*ls);
}

/*
void	*ft_regex_clean_ls(char ***ls, char ***regex, char *str,
		t_quotes *quotes)
{
	size_t	index;

	index = 0;
	while (ls[0][index])
	{
		if (ft_regex_bash(regex, ls[0][index], str) == SUCCESS)
			index++;
		else
		{
			ls[0] = ft_sarrrmi(index, ls[0]);
			if (ls[0] && regex[0])
				continue ;
			ft_sarrfree(regex);
			ft_destroy_quotes(&quotes);
			return (NULL);
		}
	}
	return (*ls);
}
*/
/*
char	**ft_regex_ls(t_quotes *quotes, char *str)
{
	char	**ls;
	size_t	index;
	char	**regex;

	if (!quotes)
		return (NULL);
	ls = ft_ls(".");
	if (!ls)
		return (NULL);
	regex = ft_regex_quotes(quotes);
	if (!regex)
		return (ft_return_regex_ls(&ls, &regex, 1));
	if (ft_quotes_unquoting(quotes) == FAILURE)
		return (ft_return_regex_ls(&ls, &regex, 1));
	if (ft_regex_clean_ls(&ls, &regex, str, quotes) == NULL)
		return (NULL);
	ft_sarrfree(&regex);
	if (ls && !ls[0])
		return (ft_regex_fail(quotes, str, &ls));
	return (ls);
}
*/
char	**ft_wordsplit_join_checks_error(char **regex, char **old)
{
	ft_sarrfree(&regex);
	free(*old);
	return (NULL);
}

char	**ft_wordsplit_join_first_regex_error(char **regex, char **words,
		int flag)
{
	if (flag > 1)
		ft_sarrfree(&regex);
	if (flag > 0)
		ft_sarrfree(&words);
	return (NULL);
}

char	**ft_wordsplit_join_first_regex_star(char **regex, char **old,
		char **words)
{
	regex = ft_sarradd(regex, *old);
	free(*old);
	*old = NULL;
	if (!regex)
		return (ft_wordsplit_join_first_regex_error(regex, words, 1));
	return (regex);
}

char	**ft_wordsplit_join_first_regex(char **regex, char **old, char **words,
		size_t *counter)
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

char	**ft_wordsplit_join_between_first_and_last(char **regex, char **words,
		size_t *counter)
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

char	**ft_wordsplit_join_add_last_regex(char **regex, char **words,
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

int	ft_isany_star(t_quotes *quotes)
{
	size_t	counter;

	counter = 0;
	if (!quotes)
		return (FAILURE);
	while (counter < quotes->counter)
	{
		if (quotes->prev_quotes && ft_strchr(quotes->prev_quotes[counter], '*'))
			return (SUCCESS);
		counter++;
	}
	if (quotes->last_unquote && !ft_char_quotes(quotes->last_unquote[0])
		&& ft_strchr(quotes->last_unquote, '*'))
		return (SUCCESS);
	return (FAILURE);
}

void	ft_regex_quotes_set(char **old, char **join, char ***regex,
		size_t *counter)
{
	*old = NULL;
	*join = NULL;
	*regex = NULL;
	*counter = 0;
}

char	**ft_regex_quotes_check(t_quotes *quote, int *quoted_last)
{
	*quoted_last = !ft_char_quotes(quote->last_unquote[0]);
	if (ft_quotes_unquoting(quote) == FAILURE)
		return (NULL);
	return ((char **)quote);
}

void	ft_regex_quotes_loop_last_step(char **join, char **old,
		char *str, size_t *counter)
{
	*old = *join;
	ft_join_(*old, str, join);
	free(*old);
	if (!*join)
		return ;
	*old = *join;
	counter[0]++;
}

char	***ft_regex_quotes_loop_if(char *str, char ***regex, char **old,
		char **join)
{
	if (ft_strchr(str, '*'))
	{
		*regex = ft_wordsplit_join(old, str, *regex);
		if (!*regex)
			return (NULL);
	}
	else
	{
		ft_join_(*old, str, join);
		if (!*join)
			return (NULL);
	}
	return (regex);
}

char	**ft_regex_quotes_loop(t_quotes *quote, char ***regex, char **old,
		size_t *counter)
{
	char	*join;

	join = NULL;
	while (*counter < quote->counter)
	{
		if (!ft_regex_quotes_loop_if(quote->prev_quotes[*counter], regex, old,
				&join))
			return (NULL);
		ft_regex_quotes_loop_last_step(&join, old,
			quote->inner_quotes[*counter], counter);
		if (!join)
			return (NULL);
	}
	return (*regex);
}

char	**ft_check_post_loop(t_quotes *quote, char ***regex, char **old,
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

char	**ft_regex_quotes_last_unquote(int quoted_last, t_quotes *quote,
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
