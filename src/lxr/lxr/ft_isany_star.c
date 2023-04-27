/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isany_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:15:36 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 10:15:45 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_isany_star(t_quotes *quotes)
{
	size_t	counter;

	counter = 0;
	if (!quotes)
		return (FAILURE);
	while (counter < quotes->counter)
	{
		if (quotes->prev_quotes && ft_strchr(quotes->prev_quotes[counter], '*'))
			return (SUCCESS);
		counter++;
	}
	if (quotes->last_unquote && !ft_char_quotes(quotes->last_unquote[0])
		&& ft_strchr(quotes->last_unquote, '*'))
		return (SUCCESS);
	return (FAILURE);
}
