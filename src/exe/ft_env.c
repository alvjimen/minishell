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
	char	**var;

	if (ft_strchr(item, '='))
	{
		var = ft_split(item, '=');
		var[0] = ft_strjoinfree(var[0], "=", 0);
		if (ft_sarrcmp(mns->env, var[0]) != -1)
		{
			return (ft_sarrrep(mns->env, ft_sarrcmp(mns->env, var[0]), item));
			printf("aLLL");
		}
		else
		{
			printf("add");
			return (ft_sarradd(mns->env, item));
		}
	}
	else
	{
		printf("hola");
		return (ft_sarradd(mns->env, item));
	}
}

// Export a variable.
// NO funciona porque está siendo ejecutado por hijos.
int	ft_export(t_tkn *cont, t_shell *mns)
{
	int		i;

	i = 0;
	while (cont->str[++i])
		mns->env = ft_update_env(cont->str[i], mns);
	ft_sarrprint(mns->env);
	return (1);
}

// Unset a variable.
// NO funciona porque está siendo ejecutado por hijos.
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
		free (var);
		if (index != -1)
			mns->env = ft_sarrrmi(index, mns->env);
	}
	ft_sarrfree(&mns->path);
	mns->path = ft_get_path(mns->env);
	ft_sarrprint(mns->env);
	return (1);
}
