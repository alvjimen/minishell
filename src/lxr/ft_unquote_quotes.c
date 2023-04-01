/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unquote_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:18:10 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/01 19:34:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	*ft_previous_quote(t_lxr **lxr, char **quote, char **value, char **prev)
{
	*tmp = ft_substr(lxr[0]->str, 0, lxr[0]->pos);
	if (!*tmp)
	{
		free(*value);
		free(*lxr);
		return (NULL);
	}
	if (VAR)
	{
		ft_putstr_fd("previous var: ", 1);
		ft_putstr_fd(*name, 1);
		ft_putstr_fd("\n", 1);
	}
	return (*tmp);
}

char	*ft_join_previos_with_var_value(t_lxr **lxr, char **name,
		char **value, char **tmp)
{
	*name = ft_strjoin(*tmp, *value);
	free(*tmp);
	free(*value);
	if (!*name)
	{
		free(*lxr);
		return (NULL);
	}
	*tmp = *name;
	if (VAR)
	{
		ft_putstr_fd("join prev + var: ", 1);
		ft_putstr_fd(*tmp, 1);
		ft_putstr_fd("\n", 1);
	}
	return (*name);
}

char	*ft_unquote_quotes(char	*str)
{
	char	*result;
	t_lxr	*lxr;
	size_t	start;

	if (!str)
		return (NULL);
	while (lxr->str[lxr->pos])
	{
		if (lxr->tokens.states != SQUOTES && lxr->str[lxr->pos] == '"')
		{
			lxr->tokens.states ^= DQUOTES;
			if (lxr->tokens.states == DQUOTES)
			{
			}
		}
		else if (lxr->tokens.states != DQUOTES && lxr->str[lxr->pos] == '\'')
			lxr->tokens.states ^= SQUOTES;
		lxr->pos++;
	}
	lxr = ft_init_lxr(str);
	return (str);
}
