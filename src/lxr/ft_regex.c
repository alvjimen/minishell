/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:26:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/20 13:15:06 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*call this after de token analizer after the var expansion*/

char	*ft_start_notstar(char **matched, char *str, size_t *counter)
{
	size_t	len;

	if (!matched || !*matched || !str || !counter)
		return (NULL);
	len = ft_strlen(str);
	if (ft_strnstr(*matched, str, len))
	{
		counter[0]++;
		*matched += len;
		return (*matched);
	}
	return (NULL);
}

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

int	ft_just_asterisk(char *regex)
{
	size_t	len;

	len = 0;
	if (!regex)
		return (SUCCESS);
	while (regex[len] == '*')
		len++;
	if (regex[len] == '\0')
		return (SUCCESS);
	return (FAILURE);
}

int	ft_clean_exit(char ***split, int value)
{
	ft_sarrfree(split);
	return (value);
}

int	ft_regex_first(char **matched, char *regex, char *split, size_t *counter)
{
	if (*regex != '*' && !ft_start_notstar(matched, split, counter))
		return (FAILURE);
	else if (*regex == '*' && ft_just_asterisk(regex) == SUCCESS)
		return (SUCCESS);
	return (NOT_TOKEN);
}

int	ft_regex(char *regex, char *matched)
{
	size_t	len;
	size_t	counter;
	char	**split;
	char	*matched_copy;

	matched_copy = matched;
	len = 0;
	counter = 0;
	if (!regex || !matched || !*regex || (*matched == '.' && *regex != '.'))
		return (FAILURE);
	split = ft_split(regex, '*');
	if (!split)
		return (FAILURE);
	if (ft_regex_first(&matched, regex, split[counter], &counter) == FAILURE)
		return (FAILURE);
	matched = ft_interstar(split, &counter, matched);
	if (!matched)
		return (FAILURE);
	len = ft_strlen(regex);
	if (len > 0)
		len--;
	if (regex[len] == '*')
		return (ft_end_star(matched, split[counter], split) == FAILURE);
	return (ft_end_notstar(matched, split[counter], &split, matched_copy));
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
{/*when regex fail*/
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

char	**ft_return_regex_ls(char ***ls, char ***regex, int flag)
{
	if (flag > 0)
		ft_sarrfree(ls);
	if (flag > 1)
		ft_sarrfree(regex);
	return (NULL);
}

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

char	**ft_wordsplit_join_checks_error(char **regex, char **old)
{
	ft_sarrfree(&regex);
	free(*old);
	return (NULL);
}

char	**ft_wordsplit_join_first_regex_error(char **regex, char **words, int flag)
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

char	**ft_wordsplit_join(char **old, char *str, char **regex)
{
	char	**words;
	char	*join;
	size_t	len_str;
	size_t	counter;

	counter = 0;
	/*Start the check part*/
	words = ft_split(str, '*');
	if (!words)
		return (ft_wordsplit_join_checks_error(regex, old));
	if (!regex && old && !*old)
		return (words);
	/*End the check part*/
	/*Start first regex*/
	if (*str == '*')
		regex = ft_wordsplit_join_first_regex_star(regex, old, words);
	else
		regex = ft_wordsplit_join_first_regex(regex, old, words, &counter);
	if (!regex)
		return (regex);
	/*
	if (*str == '*')
	{
		regex = ft_sarradd(regex, *old);
		free(*old);
		*old = NULL;
		if (!regex)
		{ft_error_first_regex
			ft_sarrfree(&words);
			return (NULL);
		}
	}
	else
	{
		if (old && *old)
			join = ft_strjoin(*old, words[counter ++]);
		else
			join = ft_strjoin("", words[counter ++]);
		free(*old);
		*old = NULL;
		if (!join)
		{ft_error_first_regex
			ft_sarrfree(&regex);
			ft_sarrfree(&words);
			return (NULL);
		}
		regex = ft_sarradd(regex, join);
		free(join);
		if (!regex)
		{
			ft_sarrfree(&words);
			return (NULL);
		}
	}
	*/
	/*End first regex*/
	while (words[counter] && words[counter + 1])
	{
		regex = ft_sarradd(regex, words[counter]);
		if (!regex)
		{
			ft_sarrfree(&words);
			return (NULL);
		}
	}
	len_str = ft_strlen(str);
	if (len_str > 1 && str[len_str - 1] == '*')
	{
		regex = ft_sarradd(regex, words[counter]);
		if (!regex)
		{
			ft_sarrfree(&words);
			return (NULL);
		}
	}
	else
	{
		if (words[counter])
		{
			*old = ft_strdup(words[counter]);
			if (!*old)
			{
				ft_sarrfree(&regex);
				ft_sarrfree(&words);
				free(join);
				join = NULL;
				return (NULL);
			}	
		}
		regex = ft_sarradd(regex, *old);
		free(*old);
		*old = NULL;
	}
	ft_sarrfree(&words);
	return (regex);
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

char	**ft_regex_quotes(t_quotes *quotes)
{
	char	**regex;
	char	*join;
	char	*old;
	size_t	counter;
	int		quoted_last;

	if (!quotes)
		return (NULL);
	old = NULL;
	join = NULL;
	regex = NULL;
	counter = 0;
	quoted_last = !ft_char_quotes(quotes->last_unquote[0]);
	if (ft_quotes_unquoting(quotes) == FAILURE)
		return (NULL);
	while (counter < quotes->counter)
	{
		if (ft_strchr(quotes->prev_quotes[counter], '*'))
		{
			regex = ft_wordsplit_join(&old, quotes->prev_quotes[counter], regex);
			if (!regex)
				return (NULL);
		}
		else
		{
			if (!old)
				join = ft_strjoin("", quotes->prev_quotes[counter]);
			else
				join = ft_strjoin(old, quotes->prev_quotes[counter]);
			free(old);
			if (!join)
				return (NULL);
		}
		old = join;
		if (!old)
			join = ft_strjoin("", quotes->inner_quotes[counter]);
		else
			join = ft_strjoin(old, quotes->inner_quotes[counter]);
		free(old);
		if (!join)
			return (NULL);
		old = join;
		counter++;
	}
	old = join;
	if (!quotes->last_unquote)
	{
		regex = ft_sarradd(regex, join);
		free(join);
		return (regex);
	}
	if (!join && counter)
	{
		ft_sarrfree(&regex);
		return (NULL);
	}
	old = join;
	if (quoted_last && ft_strchr(quotes->last_unquote, '*'))
	{
		regex = ft_wordsplit_join(&old, quotes->last_unquote, regex);
		if (!regex)
			return (NULL);
	}
	else
	{
		if (!old)
			join = ft_strjoin("", quotes->last_unquote);
		else
			join = ft_strjoin(old, quotes->last_unquote);
		free(old);
		if (!join)
			return (NULL);
		regex = ft_sarradd(regex, join);
		free(join);
		if (!regex)
			return (NULL);
	}
	return (regex);
}
