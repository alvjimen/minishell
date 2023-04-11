/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:26:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/11 20:06:55 by alvjimen         ###   ########.fr       */
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
		{
			ft_sarrfree(&split);
			return (NULL);
		}
		matched += ft_strlen(split[*counter]);
		counter[0]++;
	}	
	return (matched);
}

int	ft_end_star(char *matched, char *str, char **split)
{
	if (!str)
		return (SUCCESS);
	matched = ft_strnstr(matched, str, -1);
	ft_sarrfree(&split);
	if (!matched)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_end_notstar(char *matched, char *str, char **split,
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
		ft_sarrfree(&split);
		return (FAILURE);
	}
	matched = matched_copy + (len - len_split);
	if (!ft_strnstr(matched, str, -1))
	{
		ft_sarrfree(&split);
		return (FAILURE);
	}
	ft_sarrfree(&split);
	return (SUCCESS);
}

int	ft_just_asterisk(char *regex)
{
	size_t	len;

	len = 0;
	while (regex[len] == '*')
		len++;
	if (regex[len] == '\0')
		return (SUCCESS);
	return (FAILURE);
}

int	ft_clean_exit(char **split, int value)
{
	ft_sarrfree(&split);
	return (value);
}

/*need to calculate the len of the split*/
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
	if (*regex != '*' && !ft_start_notstar(&matched, split[counter], &counter))
		return (ft_clean_exit(split, FAILURE));
	else if (*regex == '*' && ft_just_asterisk(regex) == SUCCESS)
		return (ft_clean_exit(split, SUCCESS));
	matched = ft_interstar(split, &counter, matched);
	if (!matched)
		return (FAILURE);
	len = ft_strlen(regex);
	if (regex[len - 1] == '*')
		return (ft_end_star(matched, split[counter], split) == FAILURE);
	return (ft_end_notstar(matched, split[counter], split, matched_copy));
}

int	ft_splitted_regex(char **split, char *matched)
{
	size_t	len;
	size_t	counter;
	char	*matched_copy;

	counter = 0;
	len = 0;
	matched_copy = matched;
	if (!split || !*split || !matched || (*split[0] == '.' && *matched != '.'))
		return (FAILURE);
	if (*split[0] != '*' && !ft_start_notstar(&matched, split[counter], &counter))
		return (ft_clean_exit(split, FAILURE));
	else if (*split[0] == '*' && ft_just_asterisk(split[counter]) == SUCCESS)
		return (ft_clean_exit(split, SUCCESS));
	matched = ft_interstar(split, &counter, matched);
	if (!matched)
		return (FAILURE);
	len = ft_strlen(split[counter]);
	if (split[counter][len - 1] == '*')
		return (ft_end_star(matched, split[counter], split) == FAILURE);
	return (ft_end_notstar(matched, split[counter], split, matched_copy));
}

int	ft_regex_bash(char **regex, char *matched)
{
	size_t	len_r;
	size_t	len_m;
	size_t	index_r;

	if (!regex || !*regex || !matched)
		return (FAILURE);
	if (ft_splitted_regex(regex, matched) == SUCCESS)
	{
		len_m = ft_strlen(matched);
		index_r = ft_sarrsize(regex);
		len_r = ft_strlen(regex[index_r]);
		if (len_r > 0)
			len_r -= 1;
		else
			len_r = 0;
		if ((regex[index_r][len_r] != '/' && matched[len_m] != '/')
			|| (regex[index_r][len_r] == '/' && matched[len_m] == '/'))
			return (SUCCESS);
	}
	return (FAILURE);
}

char	**ft_regex_ls(t_quotes *quotes)
{
	char	**ls;
	size_t	index;
	char	**regex;
	char	*str;

	if (!quotes)
		return (NULL);
	ls = ft_ls(".");
	if (!ls)
		return (NULL);
	regex = ft_regex_quotes(quotes);
	if (!regex)
	{
		ft_sarrfree(&ls);
		return (NULL);
	}
	if (ft_quotes_unquoting(quotes) == FAILURE)
	{
		ft_sarrfree(&ls);
		ft_sarrfree(&regex);
		return (NULL);
	}
	index = 0;
	while (ls[index])
	{
		if (ft_regex_bash(regex, ls[index]) == SUCCESS)
			index++;
		else
		{
			ls = ft_sarrrmi(index, ls);
			if (ls)
				continue ;
			ft_sarrfree(&regex);
			return (NULL);
		}
	}
	if (ls && !ls[0])
	{
		str = ft_join_quotes(quotes);
		if (!str)
		{
			ft_sarrfree(&ls);
			ft_sarrfree(&regex);
			ft_destroy_quotes(&quotes);
		}
		else
			ft_sarradd(ls, str);
	}
	ft_sarrfree(&regex);
	return (ls);
}
/*
if (ls && !ls[0])
{
	str = ft_join_quotes(quotes);
	if (str)
		ft_sarradd(content->str, 
}
*/

char	**ft_wordsplit_join(char **old, char *str, char **regex)
{
	char	**words;
	char	**ls;
	char	*join;
	size_t	len_str;
	size_t	counter;

	counter = 0;
	words = ft_split(str, '*');
	if (!words)
	{
		ft_sarrfree(&regex);
		free(*old);
		return (NULL);
	}
	if (words[0] == NULL)
	{
		ft_sarrfree(&words);
		regex = ft_sarradd(regex, *old);
		free(*old);
		*old = NULL;
		if (!regex)
			return (NULL);
		return (regex);
	}
	len_str = ft_strlen(str);
	if (*str == '*')
	{
		regex = ft_sarradd(regex, *old);
		free(*old);
		*old = NULL;
		if (!regex)
		{
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
		{
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
	while (words[counter] && words[counter + 1])
	{
		regex = ft_sarradd(regex, words[counter]);
		if (!regex)
		{
			ft_sarrfree(&words);
			return (NULL);
		}
	}
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
		*old = ft_strdup(words[counter]);
		if (!*old)
		{
			ft_sarrfree(&regex);
			ft_sarrfree(&words);
			free(join);
			join = NULL;
			return (NULL);
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
	if (!join)
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
