/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:25:31 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:32:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static void	*ft_regex_clean_ls(char ***ls, char ***regex, char *str,
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

static char	**ft_return_regex_ls(char ***ls, char ***regex, int flag)
{
	if (flag > 0)
		ft_sarrfree(ls);
	if (flag > 1)
		ft_sarrfree(regex);
	return (NULL);
}

static char	**ft_regex_fail(t_quotes *quotes, char *str, char ***ls)
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

