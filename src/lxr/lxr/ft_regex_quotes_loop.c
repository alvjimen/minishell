/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_quotes_loop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:12:48 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 10:13:37 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	***ft_regex_quotes_loop_if(char *str, char ***regex, char **old,
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

static void	ft_regex_quotes_loop_last_step(char **join, char **old,
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
