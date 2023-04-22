/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_inside_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:46:48 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 13:04:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	*ft_expand_inside_quotes(t_quotes *quotes)
{
	size_t	counter;
	char	*str;

	if (!quotes)
		return (NULL);
	counter = 0;
	while (counter < quotes->counter)
	{
		str = ft_vars_expansion(quotes->inner_quotes[counter]);
		if (!str)
			return (NULL);
		else  if (str != quotes->inner_quotes[counter])
			free(quotes->inner_quotes[counter]);
		quotes->inner_quotes[counter] = str;
		counter++;
	}
	if (ft_char_quotes(quotes->last_unquote[0]))
	{
		str = ft_vars_expansion(quotes->last_unquote);
		if (!str)
			return (NULL);
		else  if (str != quotes->last_unquote)
			free(quotes->last_unquote);
		quotes->last_unquote = str;
	}
	return (quotes);
}
