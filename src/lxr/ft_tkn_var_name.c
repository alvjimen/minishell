/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:44:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/08 10:26:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static int	ft_valid_char(int (*f)(int), int ch)
{
	return (f(ch) || ch == '_');
}

static int	ft_char_exit_loop(t_lxr *lxr, size_t *counter)
{
	return (lxr->str[lxr->pos + *counter] == '='
			|| (lxr->str[lxr->pos + *counter] == '+'
				&& lxr->str[lxr->pos + ++counter[0]] == '='));
}

int	ft_token_varname(t_lxr	*lxr)
{
	size_t	counter;

	counter = 0;
	if (!ft_valid_char(ft_isalpha, lxr->str[lxr->pos]))
		return (ft_token_word(lxr, &counter));
	while (ft_valid_char(ft_isalnum, lxr->str[lxr->pos + counter]))
		counter++;
	if (ft_char_exit_loop(lxr, &counter))
	{
		lxr->tokens.token = ASSIGNMENT_WORD;
		ft_token_value(lxr, &counter);
		printf("Token %s:\n", "ASSIGNMENT_WORD");
		write(1, &lxr->str[lxr->pos], ++counter);
		write(1, "\n", 1);
		lxr->pos += counter;
		return (0);
	}
	return (ft_token_word(lxr, &counter));
}
