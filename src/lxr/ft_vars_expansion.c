/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:45:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/10/18 13:44:15 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
static int	ft_valid_var_name(const char *str)
{
	return (ft_isalpha(*str) || *str == '_' || *str == '$'
		|| *str == '*' || *str == '@' || *str == '?' || *str == '-');
}
static char	*ft_vars_expansion_loop(t_lxr **lxr, t_vars *vars, void *ptr)
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
			&& lxr[0]->str[lxr[0]->pos] == '$' && ft_valid_var_name(lxr[0]->str + lxr[0]->pos + 1))
		{
			aux = ft_dollar_expansion(lxr, vars, ptr);
			if (aux != lxr[0]->str)
				return (aux);
		}
		lxr[0]->pos++;
	}
	vars->tmp = lxr[0]->str;
	free(lxr[0]);
	return (vars->tmp);
}

char	*ft_vars_expansion(char *str, void *ptr)
{
	t_lxr	*lxr;
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	lxr = ft_init_lxr(str);
	if (!lxr)
		return (NULL);
	return (ft_vars_expansion_loop(&lxr, &vars, ptr));
}
