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
char	**ft_update_var(char **sarr, char *item)
{
	char	**parts;
	int		idx;

	if (ft_strchr(item, '='))
	{
		parts = ft_strbrk(item, ft_chrpos(item, '=', 0) + 1);
		idx = ft_sarrcmp(sarr, parts[0]);
		ft_sarrfree(&parts);
		if (idx == -1)
			return (ft_sarradd(sarr, item));
		else
			return (ft_sarradd(ft_sarrrmi(idx, sarr), item));
	}
	return (sarr);
}

void	ft_exportprint(t_shell *mns)
{
	int		i;
	char	**parts;

	i = -1;
	while (mns->exp[++i])
	{
		ft_printf("declare -x ");
		if (ft_chrpos(mns->exp[i], '=', 0) != -1)
		{
			parts = ft_strbrk(mns->exp[i], ft_chrpos(mns->exp[i], '=', 0) + 1);
			if (parts[1])
				printf("%s\"%s\"\n", parts[0], parts[1]);
			else
				printf("%s\"\"\n", parts[0]);
		}
		else
			printf("%s\n", mns->exp[i]);
	}
}

int	clean_exp(t_shell *mns, char *str)
{
	int		i;
	int		ret;
	char	*name;

	ret = 0;
	name = ft_substr(str, 0, ft_chrpos(str, '=', 0));
	i = -1;
	while (mns->exp[++i])
	{
		if (!ft_strncmp(name, mns->exp[i], ft_strlen(name) + 1))
		{
			ret = 1;
			mns->exp = ft_sarrrmi(i, mns->exp);
			break ;
		}
	}
	free (name);
	return (ret);
}

// Export a variable.
int	ft_export(t_tkn *cont, t_shell *mns)
{
	int		i;
	int		idx;

	i = 0;
	if (!cont->str[1])
		ft_exportprint(mns);
	while (cont->str[++i])
	{
		if (!ft_valid_identifier(cont->str[i])
			|| ft_isdefined(mns, cont->str[i]))
			continue ;
		idx = ft_equaleval(mns->vars, cont->str[i]);
		if (idx != -1 && !update_all(mns, mns->vars[idx]))
			continue ;
		while (idx >= -1 && mns->exp[++idx])
			if (!ft_strncmp(cont->str[i], mns->exp[idx],
					ft_strlen(cont->str[i]) + 1))
				idx = -2;
		if (idx != -2)
		{
			clean_exp(mns, cont->str[i]);
			mns->exp = ft_sarradd(mns->exp, cont->str[i]);
		}
	}
	return (0);
}

// Unset a variable.
int	ft_unset(t_tkn *cont, t_shell *mns)
{
	int		i;
	int		idx;
	char	*tmp;

	i = 0;
	while (cont->str[++i])
	{
		idx = ft_equaleval(mns->env, cont->str[i]);
		if (idx != -1)
			mns->env = ft_sarrrmi(idx, mns->env);
		idx = ft_equaleval(mns->vars, cont->str[i]);
		if (idx != -1)
			mns->vars = ft_sarrrmi(idx, mns->vars);
		idx = ft_equaleval(mns->exp, cont->str[i]);
		if (idx != -1)
			mns->exp = ft_sarrrmi(idx, mns->exp);
		tmp = ft_strjoin(cont->str[i], "=");
		clean_exp(mns, tmp);
		free (tmp);
	}
	ft_sarrfree(&mns->path);
	mns->path = ft_get_path(mns->env);
	return (0);
}
