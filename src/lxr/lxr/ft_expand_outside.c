/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_outside.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:49:47 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 09:37:27 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static void	*ft_expand_outside_last(t_quotes *quotes)
{
	char	*str;

	str = ft_vars_expansion(quotes->last_unquote);
	if (!str)
		return (NULL);
	else if (str != quotes->last_unquote)
		free(quotes->last_unquote);
	quotes->last_unquote = str;
	return (quotes);
}

void	*ft_expand_outside(t_quotes *quotes)
{
	size_t	counter;
	char	*str;

	if (!quotes)
		return (NULL);
	counter = 0;
	str = NULL;
	while (counter < quotes->counter)
	{
		str = ft_vars_expansion(quotes->prev_quotes[counter]);
		if (!str)
			return (NULL);
		else if (str != quotes->prev_quotes[counter])
			free(quotes->prev_quotes[counter]);
		quotes->prev_quotes[counter] = str;
		counter++;
	}
	if (quotes->last_unquote && !ft_char_quotes(*quotes->last_unquote))
		if (ft_expand_outside_last(quotes) == NULL)
			return (NULL);
	return ((void *)quotes);
}
