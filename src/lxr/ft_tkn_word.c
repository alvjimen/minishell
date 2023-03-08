/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:54:12 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/08 10:36:07 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	return 0 OK
	return 1 NOK
*/
/*
*/


int	ft_token_word(t_lxr	*lxr, size_t *counter)
{
	while (lxr->str[lxr->pos + *counter] != '\0'
		&& !ft_char_ifs(lxr->str[lxr->pos + *counter])
		&& !ft_char_operator(lxr, counter))
	{
		if (ft_char_quotes(lxr->str[lxr->pos + *counter]))
			if (!ft_quotes(lxr, counter))
				return (0);
		counter[0]++;
	}
	if (ft_char_operator(lxr, counter) || !lxr->str[lxr->pos + *counter])
	{
		lxr->tokens.token = WORD;
		printf("Token %s:\n", "WORD");
		write(1, &lxr->str[lxr->pos], counter[0]);
		write(1, "\n", 1);
		lxr->pos += counter[0];
		return (0);
	}
	if (ft_char_ifs(lxr->str[lxr->pos + *counter]))
	{
		lxr->tokens.token = WORD;
		printf("Token %s:\n", "WORD");
		write(1, &lxr->str[lxr->pos], ++counter[0]);
		write(1, "\n", 1);
		lxr->pos += *counter;
		/*
		if (!lxr->str[lxr->pos + *counter])
			return (1);
		*/
		return (0);
	}
	return (1);
}
