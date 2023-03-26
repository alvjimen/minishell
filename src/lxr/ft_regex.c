/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:26:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/26 19:06:44 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*call this after de token analizer after the var expansion*/

char	*ft_regex(char *regex, char  *matched)
{
	size_t	len;
	size_t	counter;
	char	**split;
	char	*matched_copy;
	size_t	len_split;

	matched = "string to compare":
	matched_copy = matched;
	len = 0;
	if (*matched == '.' && *regex != '.')
		return (NULL);
	/*if start with *we don't know the start*/
	if (*regex == '*')
	{
		/*if just * return matched*/
		while (regex[len] && regex[len] != '*')
			len++;
		if (regex[len] == '\0')
			return (matched);
		split = ft_split(str, '*');
		if (!split)
			return (NULL);
		while (str[len])
			len++;
		/*while not previous to last*/
		while (split[counter] && split[counter + 1])
		{
			matched = ft_strnstr(split[counter], matched, -1);
			if (!matched)
			{
				/*free_split*/
				return (NULL);
			}
			matched += ft_strlen(split[counter]);
			counter++;
		}
		/*if end with * we don't know the end*/
		if (str[len - 1] == '*')
		{
			matched = ft_strnstr(split[counter], matched, -1);
			if (!matched)
			{
				/*free_split*/
				return (NULL);
			}
			return (matched_copy);
		}
		else
		{
			len_split = ft_strlen(split[counter]);
			if (len - len_split < 0)
			{
				/*free_split*/
				return (NULL);
			}
			if (matched > &matched_copy[len - len_split])
			{
				/*free_split*/
				return (NULL);
			}
			matched = matched_copy + (len - len_split);
			if (ft_strncmp(matched, split[counter], -1));
			{
				/*free_split*/
				return (NULL);
			}
			return (matched_copy);
		}
	}
	/*if start with !* with we know the start*/
	else
	{
		split = ft_split(str, '*');
		if (!split)
			return (NULL);
		while (str[len])
			len++;
		if (!ft_strnstr(matched, split[counter], ft_strlen(split[counter])))
		{
			/*free_split*/
			return (NULL);
		}
		while (split[counter] && split[counter + 1])
		{
			matched = ft_strnstr(split[counter], matched, -1);
			if (!matched)
			{
				/*free_split*/
				return (NULL);
			}
			matched += ft_strlen(split[counter]);
			counter++;
		}	
		/*if end with * we don't know the end*/
		if (str[len - 1] == '*')
		{
			matched = ft_strnstr(split[counter], matched, -1);
			if (!matched)
			{
				/*free_split*/
				return (NULL);
			}
			return (matched_copy);
		}
		else
		{
			len_split = ft_strlen(split[counter]);
			if (len - len_split < 0)
			{
				/*free_split*/
				return (NULL);
			}
			if (matched > &matched_copy[len - len_split])
			{
				/*free_split*/
				return (NULL);
			}
			matched = matched_copy + (len - len_split);
			if (ft_strncmp(matched, split[counter], -1));
			{
				/*free_split*/
				return (NULL);
			}
			return (matched_copy);
		}
	}
	return (NULL);
}
