/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_inside_quotes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:46:48 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 17:01:51 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	*ft_aux_vars_expansion(char *str)
{
	char	*tmp;

	tmp = ft_vars_expansion(str);
	if (!str)
		return (NULL);
	else if (tmp != str)
		free(str);
	return (tmp);
}

void	*ft_expand_inside_quotes(t_quotes *quotes)
{
	size_t	counter;
	char	*str;

	if (!quotes)
		return (NULL);
	counter = 0;
	while (counter < quotes->counter)
	{
		str = ft_aux_vars_expansion(quotes->inner_quotes[counter]);
		if (!str)
			return (NULL);
		quotes->inner_quotes[counter] = str;
		counter++;
	}
	if (ft_char_quotes(quotes->last_unquote[0]))
	{
		str = ft_aux_vars_expansion(quotes->last_unquote);
		if (!str)
			return (NULL);
		quotes->last_unquote = str;
	}
	return (quotes);
}
