/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:40:07 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/23 20:40:07 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"

/* If the item given is already in envp, update it
else is added */
char	**ft_update_env(char *item, t_shell *mns)
{
	char	**parts;
	int		idx;

	if (ft_strchr(item, '='))
	{
		parts = ft_strbrk(item, ft_chrpos(item, '=', 0) + 1);
		idx = ft_sarrcmp(mns->env, parts[0]);
		ft_sarrfree(&parts);
		if (idx == -1)
			return (ft_sarradd(mns->env, item));
		else
			return (ft_sarradd(ft_sarrrmi(idx, mns->env), item));
	}
	return (mns->env);
}

// Export a variable.
int	ft_export(t_tkn *cont, t_shell *mns)
{
	int		i;
	int		idx;
	char	*temp;

	i = 0;
	while (cont->str[++i])
	{
		if (!ft_strchr(cont->str[i], '='))
			temp = ft_strjoin(cont->str[i], "=");
		else
			temp = ft_strdup(cont->str[i]);
		idx = ft_sarrcmp(mns->vars, temp);
		if (idx == -1)
			mns->env = ft_update_env(temp, mns);
		else
			mns->env = ft_update_env(mns->vars[idx], mns);
		free (temp);
	}
	return (0);
}

// Unset a variable.
int	ft_unset(t_tkn *cont, t_shell *mns)
{
	int		index;
	char	*var;
	int		i;

	i = 0;
	while (cont->str[++i])
	{
		var = ft_strjoin(cont->str[i], "=");
		index = ft_sarrcmp(mns->env, var);
		if (index != -1)
			mns->env = ft_sarrrmi(index, mns->env);
		index = ft_sarrcmp(mns->vars, var);
		free (var);
		if (index != -1)
			mns->vars = ft_sarrrmi(index, mns->vars);
	}
	ft_sarrfree(&mns->path);
	mns->path = ft_get_path(mns->env);
	return (0);
}
