/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:54:12 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/15 06:39:10 by alvjimen         ###   ########.fr       */
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
	if (!*counter && (lxr->str[lxr->pos + *counter] == '\0'
		|| ft_char_ifs(lxr->str[lxr->pos + *counter])
		|| ft_char_operator(lxr, counter)))
	{
		ft_putstr_fd("Not a word\n", 1);
		return (NOT_TOKEN);
	}
	while (lxr->str[lxr->pos + *counter] != '\0'
		&& !ft_char_ifs(lxr->str[lxr->pos + *counter])
		&& !ft_char_operator(lxr, counter))
	{
		if (ft_quotes(lxr, counter) == NOT_TOKEN)
			return (NOT_TOKEN);
		counter[0]++;
	}
	if (ft_char_operator(lxr, counter) || !lxr->str[lxr->pos + *counter]
		|| (ft_char_ifs(lxr->str[lxr->pos + *counter])))
	{
		lxr->tokens.token = WORD;
		ft_putstr_fd("Token WORD:\n", 1);
		write(1, &lxr->str[lxr->pos], counter[0]);
		write(1, "\n", 1);
		lxr->pos += counter[0];
		return (0);
	}
	ft_putstr_fd("Not a word\n", 1);
	return (NOT_TOKEN);
}
