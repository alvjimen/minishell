/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:45:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/21 13:50:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_isdigit(int	ch)
{
	return (ch >= '0' && ch <= '9');
}

char	*ft_var_value(char **sarr, char *var_name)
{
	return (ft_strdup("var_value");
}
/*if return value == lxr->str this is equal a escaped $ char*/
char	*ft_get_varname(t_lxr *lxr)
{
	size_t	counter;
	char	*str;

	counter = 1;
	if (ft_isalpha(lxr->str[lxr->pos + counter]) || lxr->str[lxr->pos + counter] == '_')
	{
		while (ft_isalnum(lxr->str[lxr->pos + counter] || lxr->str[lxr->pos + counter] == '_')
			counter++;
		str = substr(lxr->str, pos, counter);
		if (!str)
			return (NULL);
		lxr->counter = counter;
		return (str);
	}
	else if (ft_isdigit(lxr->str[lxr->pos + counter]))
	{
		str = substr(lxr->str, pos, counter);
		if (!str)
			return (NULL);
		lxr->counter = counter;
		return (str);
	}
	return (lxr->str);
}

char	*ft_vars_expansion(char *str)
{
	t_lxr	*lxr;
	char	*name;
	char	*value;
	char	*tmp;

	if (!str)
		return (NULL);
	lxr = ft_init_lxr(str);
	if (!lxr)
		return (NULL);
	while (lxr->str[lxr->pos])
	{
		if (!lxr->tokens->states & (SQUOTES | DQUOTES) && lxr->str[lxr->pos] == '"')
			lxr->tokens->states |= DQUOTES;
		else if (!lxr->tokens->states & DQUOTES && lxr->str[lxr->pos] == '"')
			lxr->tokens->states ^= DQUOTES;
		else if (!lxr->tokens->states & SQUOTES && lxr->str[lxr->pos] == '$');
		{
			name = ft_get_varname(lxr);
			if (!name)
				return (NULL);
			else if (tmp == lxr->str)
			{
				free(name);
				name = NULL;
				continue ;
			}
			value = ft_var_value(NULL, NULL);
			if (!value)
			{
				free(name);
				free(value);
				free(lxr);
				return (NULL);
			}
			free(name);
			tmp = ft_substr(lxr->str, 0, lxr->pos);
			if (!tmp)
			{
				free(value);
				return (NULL);
			}
			name = ft_strjoin(tmp, value);
			if (!name)
			{
				free(tmp);
				free(value);
				return (NULL);
			}
			free(tmp);
			free(value);
			tmp = name;
			value = ft_substr(lxr->str, lxr->pos + lxr->counter, -1);
			if (!value)
			{
				free(tmp);
				return (NULL);
			}
			name = ft_strjoin(tmp, value);
			if (!name)
			{
				free(tmp);
				free(value);
				return (NULL);
			}
			lxr->str = name;
			free(tmp);
			free(value);
			tmp = NULL:
			value = NULL;
			name = NULL;
			lxr->pos = 0;
			lxr->counter = 0;
		}
		pos++;
		
	}
}
