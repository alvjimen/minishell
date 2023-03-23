/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:45:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/23 19:21:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	*ft_var_value(char **sarr, char *var_name)
{
	return (ft_strdup("var_value"));
}

/*
if return value == lxr->str this is equal a escaped $ char
$1 'value'
$da1 'value'
$  '$'
check
i don't take the dollar value.
*/
void	ft_dollar_expansion(t_lxr **lxr, char **name, char **value, char **tmp)
{
	name[0] = ft_get_varname(*lxr);
	if (!*name)
		return (NULL);
	else if (*tmp == *lxr->str)
	{
		free(*name);
		continue ;
	}
	*value = ft_var_value(NULL, *name);
	free(*name);
	if (!*value)
	{
		free(*lxr);
		return (NULL);
	}
	*tmp = ft_substr(lxr[0]->str, 0, lxr[0]->pos);
	if (!*tmp)
	{
		free(*value);
		free(*lxr);
		return (NULL);
	}
	*name = ft_strjoin(*tmp, *value);
	free(*tmp);
	free(*value);
	if (!*name)
	{
		free(*lxr);
		return (NULL);
	}
	*tmp = *name;
	*value = ft_substr(lxr[0]->str, lxr[0]->pos + lxr[0]->counter, -1);
	if (!value[0])
	{
		free(tmp[0]);
		free(lxr[0]);
		return (NULL);
	}
	name[0] = ft_strjoin(tmp[0], value[0]);
	if (!name[0])
	{
		free(tmp[0]);
		free(value[0]);
		free(lxr[0]);
		return (NULL);
	}
	lxr[0]->str = name[0];
	free(tmp[0]);
	free(value[0]);
	tmp[0] = NULL;
	value[0] = NULL;
	name[0] = NULL;
	lxr[0]->pos = 0;
	lxr[0]->counter = 0;
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
		if (!lxr->tokens->states & (SQUOTES | DQUOTES)
			&& lxr->str[lxr->pos] == '"')
			lxr->tokens->states |= DQUOTES;
		else if (!lxr->tokens->states & DQUOTES
			&& lxr->str[lxr->pos] == '"')
			lxr->tokens->states ^= DQUOTES;
		else if (!lxr->tokens->states & SQUOTES
			&& lxr->str[lxr->pos] == '$')
		{
			ft_dollar_expansion(&lxr, &name, &value, &tmp);
			/*
			name = ft_get_varname(lxr);
			if (!name)
				return (NULL);
			else if (tmp == lxr->str)
			{
				free(name);
				continue ;
			}
			value = ft_var_value(NULL, name);
			free(name);
			if (!value)
			{
				free(lxr);
				return (NULL);
			}
			tmp = ft_substr(lxr->str, 0, lxr->pos);
			if (!tmp)
			{
				free(value);
				free(lxr);
				return (NULL);
			}
			name = ft_strjoin(tmp, value);
			free(tmp);
			free(value);
			if (!name)
			{
				free(lxr);
				return (NULL);
			}
			tmp = name;
			value = ft_substr(lxr->str, lxr->pos + lxr->counter, -1);
			if (!value)
			{
				free(tmp);
				free(lxr);
				return (NULL);
			}
			name = ft_strjoin(tmp, value);
			if (!name)
			{
				free(tmp);
				free(value);
				free(lxr);
				return (NULL);
			}
			lxr->str = name;
			free(tmp);
			free(value);
			tmp = NULL;
			value = NULL;
			name = NULL;
			lxr->pos = 0;
			lxr->counter = 0;
			*/
		}
		lxr->pos++;
	}
	free(lxr);
	return (lxr->str);
}
