/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:44:38 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 08:45:46 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static void	*ft_join_quotes_loop(t_quotes *quotes, char **old, char **join)
{
	size_t	counter;

	counter = 0;
	while (counter < quotes->counter)
	{
		ft_join_(*old, quotes->prev_quotes[counter], join);
		free(*old);
		if (!*join)
			return (NULL);
		*old = *join;
		*join = ft_strjoin(*old, quotes->inner_quotes[counter++]);
		free(*old);
		if (!*join)
			return (NULL);
		*old = *join;
	}
	return (join);
}

void	*ft_join_quotes(t_quotes *quotes)
{
	char	*old;
	char	*join;
	size_t	counter;

	old = NULL;
	join = NULL;
	counter = 0;
	if (!quotes)
		return (NULL);
	if (ft_join_quotes_loop(quotes, &old, &join) == NULL)
		return (NULL);
	if (!quotes->last_unquote)
		return (join);
	ft_join_(old, quotes->last_unquote, &join);
	free(old);
	return (join);
}
