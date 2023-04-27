/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:54:12 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/21 13:23:11 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	Return Value Status
	O				ALL OK.
	NOT_TOKEN		NOT Complete value "' doesn't not end.
*/

int	ft_token_word(t_lxr	*lxr, size_t *counter)
{
	while (lxr->str[lxr->pos + *counter] != '\0'
		&& !ft_char_ifs(lxr->str[lxr->pos + *counter])
		&& !ft_char_operator(lxr, counter))
	{
		if (ft_quotes(lxr, counter) == FAILURE)
			return (FAILURE);
		counter[0]++;
	}
	if (ft_char_operator(lxr, counter) || !lxr->str[lxr->pos + *counter]
		|| (ft_char_ifs(lxr->str[lxr->pos + *counter])))
	{
		lxr->tokens.token = WORD;
		lxr->tokens.operators = NONE;
		if (ft_add_string_to_list(lxr, *counter) == NULL)
			return (NOT_TOKEN);
		return (SUCCESS);
	}
	ft_putstr_fd("Not a word\n", 1);
	return (NOT_TOKEN);
}
