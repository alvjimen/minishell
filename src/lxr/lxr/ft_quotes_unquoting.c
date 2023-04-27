/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_unquoting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:56:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 10:05:03 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	*ft_unquote(char *str)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	if (len <= 2)
		tmp = ft_strdup("");
	else
		tmp = ft_substr(str, 1, len - 2);
	return (tmp);
}

static char	*ft_quotes_unquoting_loop(t_quotes *quotes)
{
	char	*str;
	char	*tmp;
	size_t	counter;

	counter = 0;
	tmp = (char *)quotes;
	while (counter < quotes->counter)
	{
		str = quotes->inner_quotes[counter];
		if (!str)
			return (NULL);
		tmp = ft_unquote(str);
		if (!tmp)
			return (NULL);
		quotes->inner_quotes[counter++] = tmp;
		free(str);
	}
	return (tmp);
}

int	ft_quotes_unquoting(t_quotes *quotes)
{
	char	*str;
	char	*tmp;

	if (!quotes)
		return (FAILURE);
	if (ft_quotes_unquoting_loop(quotes) == NULL)
		return (FAILURE);
	if (ft_char_quotes(quotes->last_unquote[0]))
	{
		str = quotes->last_unquote;
		if (!str)
			return (FAILURE);
		tmp = ft_unquote(str);
		if (!tmp)
			return (FAILURE);
		quotes->last_unquote = tmp;
		free(str);
	}
	return (SUCCESS);
}
