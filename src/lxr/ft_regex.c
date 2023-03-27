/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:26:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/27 19:30:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*call this after de token analizer after the var expansion*/

char	*ft_start_notstar(char *matched, char *str)
{
	if (!matched || !str)
		return (NULL);
	return (ft_strnstr(matched, str, ft_strlen(str)));
}

char	*ft_interstar(char **split, size_t *counter, char *matched)
{
	while (split[*counter] && split[*counter + 1])
	{
		matched = ft_strnstr(split[*counter], matched, -1);
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
	matched = ft_strnstr(str, matched, -1);
	if (!matched)
	{
		ft_sarrfree(&split);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_end_notstar(char *matched, char *str, char **split,
		char *matched_copy)
{
	size_t	len_split;
	size_t	len;
	size_t	counter;

	len_split = ft_strlen(str);
	len = ft_strlen(matched_copy);
	if (len - len_split < 0 || matched >= &matched_copy[len - len_split])
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
	return (SUCCESS);
}

int	ft_just_asterisk(char *regex, size_t len)
{
	while (regex[len] == '*')
		len++;
	if (regex[len] == '\0')
		return (SUCCESS);
	return (FAILURE);
}

int	ft_regex(char *regex, char  *matched)
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
	if (*regex != '*' && !ft_start_notstar(matched, split[counter]))
		return (FAILURE);
	else if (*regex == '*' && ft_just_asterisk(regex, len) == SUCCESS)
		return (SUCCESS);
	matched = ft_interstar(split, &counter, matched);
	if (!matched)
		return (FAILURE);
	len = ft_strlen(regex);
	if (regex[len - 1] == '*')
		return (ft_end_star(matched, split[counter], split) == FAILURE);
	return (ft_end_notstar(matched, split[counter], split, matched_copy));
}
