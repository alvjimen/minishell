/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_bash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:58:31 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 09:43:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	*ft_interstar(char **split, size_t *counter, char *matched)
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

static int	ft_end_star(char *matched, char *str, char **split)
{
	split = NULL;
	if (split)
			return (FAILURE);
	if (!str)
		return (SUCCESS);
	matched = ft_strnstr(matched, str, -1);
	if (!matched)
		return (FAILURE);
	return (SUCCESS);
}

static int	ft_end_notstar(char *matched, char *str, char ***split,
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

static int	ft_splitted_regex(char ***split, char *matched, char *regex)
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
