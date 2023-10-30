/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:04:17 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/02 20:04:19 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

int	search_replace(char ***sarr, char *var, char *val)
{
	int		idx;

	idx = ft_sarrcmp(*sarr, var);
	if (idx == -1)
		*sarr = ft_sarradd(*sarr, val);
	else
		*sarr = ft_sarradd(ft_sarrrmi(idx, *sarr), val);
	return (idx);
}

int	update_all(t_shell *mns, char *value)
{
	mns->exp = ft_update_var(mns->exp, value);
	mns->env = ft_update_var(mns->env, value);
	mns->vars = ft_update_var(mns->vars, value);
	mns->path = ft_get_path(mns->env);
	if (!mns->path)
		mns->path = ft_get_path(mns->vars);
	free (value);
	return (0);
}

int	ft_isvar(t_shell *mns, t_tkn *cont)
{
	char	**parts;
	int		idx;
	int		i;

	i = -1;
	while (cont->str[++i])
	{
		if (!ft_valid_identifier(cont->str[i]))
			return (1);
		if (clean_exp(mns, cont->str[i]))
			return (update_all(mns, ft_strdup(cont->str[i])));
		mns->vars = ft_update_var(mns->vars, cont->str[i]);
		if (!mns->path)
			mns->path = ft_get_path(mns->vars);
		parts = ft_strbrk(cont->str[i], ft_chrpos(cont->str[i], '=', 0) + 1);
		idx = ft_sarrcmp(mns->env, parts[0]);
		if (idx != -1)
			mns->env = ft_update_var(mns->env, cont->str[i]);
		idx = ft_sarrcmp(mns->exp, parts[0]);
		if (idx != -1)
			update_all(mns, ft_strdup(cont->str[i]));
		ft_sarrfree(&parts);
	}
	return (0);
}
