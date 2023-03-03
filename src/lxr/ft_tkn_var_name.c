/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:44:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/03 14:43:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	TODO There for see what is going on
	Maybe i should take off also the spaces for now on.
*/

static	int	ft_valid_char(int (*f)(int), int ch)
{
	return (f(ch) || ch == '_');
}

int	ft_token_varname(t_lxr	*lxr, size_t *counter)
{
	int	i;

	lxr->pos += ft_run_ifs(lxr);
	if (ft_valid_char(ft_isalpha, lxr->str[lxr->pos]))
	{
		while (ft_valid_char(ft_isalnum, lxr->str[lxr->pos + counter[0]]))
			counter[0]++;
		if (lxr->str[lxr->pos + counter[0]] == '=')
		{
			lxr->tokens.token_s = ASSIGNMENT_WORD;
			i = ft_token_name(lxr, &counter[0])
			if (i)
			{
				printf("Token %s:\n", "ASSIGNMENT_WORD");
				write(1, &lxr->str[lxr->pos], ++counter[0]);
				write(1, "\n", 1);
			}
			else
			lxr->pos += counter[0];
			counter[0];
			return (0);
		}
	}
}
