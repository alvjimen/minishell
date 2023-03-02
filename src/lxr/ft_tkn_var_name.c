/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:44:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/02 17:27:11 by alvjimen         ###   ########.fr       */
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

void	ft_token_varname(t_lxr	*lxr)
{
	size_t	counter;

	lxr->pos += ft_run_ifs(lxr);
	counter = 0;
	if (ft_valid_char(ft_isalpha, lxr->str[lxr->pos]))
	{
		while (ft_valid_char(ft_isalnum, lxr->str[lxr->pos + counter]))
			counter++;
		if (lxr->str[lxr->pos + counter] == '=')
		{
			lxr->tokens.token_s = ASSIGNMENT_WORD;
			write(1, &lxr->str[lxr->pos], ++counter);
			write(1, "\n", 1);
			lxr->pos += counter;
			ft_token_name(lxr);
		}
		else
		{
			printf("Token %s:\n", "WORD");
			write(1, &lxr->str[lxr->pos], counter);
			write(1, "\n", 1);
		}
	}
	else
		{
			printf("Token %s:\n", "WORD");
			write(1, &lxr->str[lxr->pos], counter);
			write(1, "\n", 1);
		}
}
