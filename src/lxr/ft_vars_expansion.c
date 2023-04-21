/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:45:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/21 20:51:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	*ft_vars_expansion_loop(t_lxr **lxr, t_vars *vars)
{
	char	*aux;

	while (lxr[0]->str[lxr[0]->pos])
	{
		if (lxr[0]->tokens.states != SQUOTES
			&& lxr[0]->str[lxr[0]->pos] == '"')
			lxr[0]->tokens.states ^= DQUOTES;
		else if (lxr[0]->tokens.states != DQUOTES
			&& lxr[0]->str[lxr[0]->pos] == '\'')
			lxr[0]->tokens.states ^= SQUOTES;
		else if (lxr[0]->tokens.states != SQUOTES
			&& lxr[0]->str[lxr[0]->pos] == '$')
		{
			aux = ft_dollar_expansion(lxr, vars);
			if (aux != lxr[0]->str)
				return (aux);
		}
		lxr[0]->pos++;
	}
	vars->tmp = lxr[0]->str;
	free(lxr[0]);
	return (vars->tmp);
}

char	*ft_vars_expansion(char *str)
{
	t_lxr	*lxr;
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	lxr = ft_init_lxr(str);
	if (!lxr)
		return (NULL);
	return (ft_vars_expansion_loop(&lxr, &vars));
}
