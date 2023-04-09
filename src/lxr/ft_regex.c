/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:26:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/09 19:03:34 by alvjimen         ###   ########.fr       */
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

int	ft_regex_bash(char *regex, char *matched)
{
	size_t	len_r;
	size_t	len_m;

	if (!regex || !matched)
		return (FAILURE);
	if (ft_regex(regex, matched) == SUCCESS)
	{
		len_m = ft_strlen(matched);
		len_r = ft_strlen(regex);
		if (len_r > 0)
			len_r -= 1;
		else
			len_r = 0;
		if ((regex[len_r] != '/' && matched[len_m] != '/')
			|| (regex[len_r] == '/' && matched[len_m] == '/'))
			return (SUCCESS);
	}
	return (FAILURE);
}

char	**ft_regex_ls(char	*regex)
{
	char	**ls;
	size_t	index;

	if (!regex)
		return (NULL);
	ls = ft_ls(".");
	if (!ls)
		return (NULL);
	index = 0;
	while (ls[index])
	{
		if (ft_regex_bash(regex, ls[index]) == SUCCESS)
			index++;
		else
		{
			ls = ft_sarrrmi(index, ls);
			if (!ls)
				return  (NULL);
		}
	}
	return (ls);
}

char	**ft_regex_quotes(t_quotes *quotes)
{
	char	**words;
	char	**regex;
	char	*join;
	char	*old;
	char	*tmp;
	size_t	counter;

	if (!quotes)
		return (NULL);
	words = NULL;
	old = NULL;
	tmp = NULL;
	regex = NULL;
	counter = 0;
	while (counter < quotes->counter)
	{
		if (quotes->prev_quotes[counter]
			&& ft_strchr(quotes->prev_quotes[counter], '*'))
		{
			words = ft_split(quotes->prev_quotes[counter], '*');
			if (!words)
			{
				ft_sarrfree(&regex);
				return (NULL);
			}
			old = ft_strjoin(old, words[0]);
			if (!old)
			{
				free(join);
				ft_sarrfree(&regex);
				return (NULL);
			}
			regex = ft_sarradd(regex, old);
			free(join);
			free(old);
			if (!regex)
				return (NULL);
			old = ft_strdup(words[1]);
			ft_sarrfree(&words);
			if (!old)
			{
				free(tmp);
				free(tmp);
				return (NULL);
			}
		}
		else
		{
			if (!old)
				join = ft_strjoin("", quotes->prev_quotes[counter]);
			else
				join = ft_strjoin(old, quotes->prev_quotes[counter]);
		}
		free(old);
		if (!join)
			return (NULL);
		old = join;
		join = ft_strjoin(old, quotes->inner_quotes[counter]);
		free(old);
		if (!join)
			return (NULL);
		old = join;
		counter++;
	}
	old = join;
	if (!old)
	{
		old = ft_strdup("");
		if (!old)
			return (NULL);
	}
	if (!quotes->last_unquote)
		return (words);
	join = ft_strjoin(old, quotes->last_unquote);
	free(old);
	if (!join)
		return (NULL);
	if (ft_strchr(quotes->last_unquote, '*'))
	{
		words = ft_split(quotes->last_unquote, '*');
		if (!words)
		{
			ft_sarrfree(&regex);
			return (NULL);
		}
		old = ft_strjoin(old, words[0]);
		if (!old)
		{
			free(join);
			ft_sarrfree(&regex);
			return (NULL);
		}
		regex = ft_sarradd(regex, old);
		free(join);
		free(old);
		if (!regex)
			return (NULL);
		old = ft_strdup(words[1]);
		ft_sarrfree(&words);
		if (!old)
		{
			free(tmp);
			free(join);
			return (NULL);
		}
	}
	//return (join);
	return (regex);
}
