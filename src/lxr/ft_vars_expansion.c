/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:45:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/04 22:47:12 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	*ft_var_value(char **sarr, char *var_name)
{
	sarr = NULL;
	var_name = NULL;
	return (ft_strdup("var value"));
}

char	*ft_previous_var(t_lxr **lxr, char **name, char **value,
		char **tmp)
{
	*value = ft_var_value(NULL, *name);
	if (VAR)
	{
		ft_putstr_fd("value of var: ", 1);
		ft_putstr_fd(*value, 1);
		ft_putstr_fd("\n", 1);
	}
	free(*name);
	*name = NULL;
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
	if (VAR)
	{
		ft_putstr_fd("previous var: ", 1);
		ft_putstr_fd(*name, 1);
		ft_putstr_fd("\n", 1);
	}
	return (*tmp);
}

	/*Join the previos var with the value of the var*/
char	*ft_join_previos_with_var_value(t_lxr **lxr, char **name,
		char **value, char **tmp)
{
	*name = ft_strjoin(*tmp, *value);
	free(*tmp);
	*tmp = NULL;
	free(*value);
	*value = NULL;
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

/*Get the after var with the value of the var*/
char	*ft_after_var(t_lxr **lxr, char **name,
		char **value, char **tmp)
{
	char	*aux;

	name = NULL;
	aux = lxr[0]->str + lxr[0]->pos + lxr[0]->counter;
	*value = ft_substr(lxr[0]->str, lxr[0]->pos + lxr[0]->counter,
			ft_strlen(aux));
	if (!value[0])
	{
		free(tmp[0]);
		*tmp = NULL;
		free(lxr[0]);
		*lxr = NULL;
		return (NULL);
	}
	if (VAR)
	{
		ft_putstr_fd("after var: ", 1);
		ft_putstr_fd(*value, 1);
		ft_putstr_fd("\n", 1);
	}
	return (*value);
}

/*Join the previos var with the value of the var*/
char	*ft_join_str(t_lxr **lxr, char **name, char **value, char **tmp)
{
	name[0] = ft_strjoin(tmp[0], value[0]);
	free(tmp[0]);
	free(value[0]);
	tmp[0] = NULL;
	value[0] = NULL;
	if (!name[0])
	{
		free(lxr[0]);
		return (NULL);
	}
	if (VAR)
	{
		ft_putstr_fd("join of all the token: ", 1);
		ft_putstr_fd(*name, 1);
		ft_putstr_fd("\n", 1);
	}
	return (name[0]);
}

char	*ft_dollar_expansion(t_lxr **lxr, char **name, char **value, char **tmp)
{
	name[0] = ft_get_varname(*lxr);
	if (!*name)
		return (lxr[0]->str);
	else if (*tmp == lxr[0]->str)
	{
		free(*name);
		lxr[0]->pos++;
		return (lxr[0]->str);
	}
	if (ft_previous_var(lxr, name, value, tmp) == NULL)
		return (NULL);
	if (ft_join_previos_with_var_value(lxr, name, value, tmp) == NULL)
		return (NULL);
	if (ft_after_var(lxr, name, value, tmp) == NULL)
		return (NULL);
	if (ft_join_str(lxr, name, value, tmp) == NULL)
		return (NULL);
	lxr[0]->str = name[0];
	name[0] = NULL;
	lxr[0]->pos = 0;
	lxr[0]->counter = 0;
	return (lxr[0]->str);
}

char	*ft_vars_expansion(char *str)
{
	t_lxr	*lxr;
	char	*name;
	char	*value;
	char	*tmp;
	char	*aux;

	if (!str)
		return (NULL);
	tmp = NULL;
	value = NULL;
	aux = NULL;
	name = NULL;
	lxr = ft_init_lxr(str);
	if (!lxr)
		return (NULL);
	while (lxr->str[lxr->pos])
	{
		if (lxr->tokens.states != SQUOTES && lxr->str[lxr->pos] == '"')
			lxr->tokens.states ^= DQUOTES;
		else if (lxr->tokens.states != DQUOTES && lxr->str[lxr->pos] == '\'')
			lxr->tokens.states ^= SQUOTES;
		else if (lxr->tokens.states != SQUOTES && lxr->str[lxr->pos] == '$')
		{
			aux = ft_dollar_expansion(&lxr, &name, &value, &tmp);
			if (aux != lxr->str)
				return (aux);/*aux == NULL*/
		}
		lxr->pos++;
	}
	tmp = lxr->str;
	free(lxr);
	if (VAR)
	{
		ft_putstr_fd("Var expansion: ", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("\n", 1);
	}
	return (tmp);
}

void	ft_vars_expansion_recursively(void **ptr)
{
	char	*str;
	t_btree	**root;
	t_tkn	*content;

	root = (t_btree **)ptr;
	content = root[0]->content;
	if (!content)
		return ;
	str = ft_vars_expansion(content->value);
	content->value = str;
	/*
	if (!str)
		content->states = ERROR;
	 */
}
