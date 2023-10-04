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

int	ft_isvar(t_shell *mns, t_tkn *cont)
{
	char	**parts;
	int		idx;

	idx = -1;
	while (cont->value[++idx] != '=')
		if (!ft_isalnum(cont->value[idx]))
			return (1);
	parts = ft_strbrk(cont->value, ft_chrpos(cont->value, '=', 0) + 1);
	idx = ft_sarrcmp(mns->env, parts[0]);
	if (idx != -1)
		search_replace(&mns->env, parts[0], cont->value);
	else
		search_replace(&mns->vars, parts[0], cont->value);
	ft_sarrfree(&parts);
	return (0);
}
