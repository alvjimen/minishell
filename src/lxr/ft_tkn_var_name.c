/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:44:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/03 20:05:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static	int	ft_valid_char(int (*f)(int), int ch)
{
	return (f(ch) || ch == '_');
}
/* Interchange ++counter[0]
			if (lxr->str[lxr->pos + counter[0]] == '+')
				counter[0] ++;
			*/

int	ft_token_varname(t_lxr	*lxr)
{
	size_t	counter;

	lxr->pos += ft_run_ifs(lxr);
	if (ft_valid_char(ft_isalpha, lxr->str[lxr->pos]))
	{
		while (ft_valid_char(ft_isalnum, lxr->str[lxr->pos + counter]))
			counter++;
		if (lxr->str[lxr->pos + counter] == '='
			|| (lxr->str[lxr->pos + counter] == '+'
				&& lxr->str[lxr->pos + ++counter] == '='))
		{
			lxr->tokens.token_s = ASSIGNMENT_WORD;
			if (ft_token_name(lxr, &counter))
			{
				printf("Token %s:\n", "ASSIGNMENT_WORD");
				write(1, &lxr->str[lxr->pos], ++counter);
				write(1, "\n", 1);
				lxr->pos += counter;
				return (0);
			}
			else
				printf("Error parsing\n");
		}
	}
	return (1);
}
