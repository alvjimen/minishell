/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:54:12 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/06 14:46:15 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	return 1 == end of line or ifs i should make a modification to still taking
	chars for the token word before a quote
*/

int	ft_token_word(t_lxr	*lxr, size_t *counter)
{
	lxr->pos = ft_run_ifs(lxr);
	while (lxr->str[lxr->pos + *counter] != '\0'
		&& !ft_char_ifs(lxr->str[lxr->pos + *counter])
		&& !ft_char_operator(lxr->str[lxr->pos + *counter])
		&& !ft_char_quotes(lxr->str[lxr->pos + *counter]))
		counter[0]++;
	if (ft_char_operator(lxr->str[lxr->pos + *counter]))
	{
		lxr->tokens.token_s = WORD;
		printf("Token %s:\n", "WORD");
		write(1, &lxr->str[lxr->pos], ++counter);
		write(1, "\n", 1);
		lxr->pos += counter;
		counter = 0;
		ft_operators(lxr, counter);
		return (0);
	}
	else if (ft_char_quotes(lxr->str[lxr->pos + *counter]))
	{
		ft_quotes(lxr, counter);
		lxr->tokens.token_s = WORD;
		printf("Token %s:\n", "WORD");
		write(1, &lxr->str[lxr->pos], ++counter);
		write(1, "\n", 1);
		lxr->pos += counter;
		return (0);
	}
	return (1);
}
