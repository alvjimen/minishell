/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:00:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 14:39:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include "mns.h"

char	*get_var_value(char **sarr, char *var)
{
	int		idx;
	char	**parts;
	char	*value;

	idx = ft_sarrcmp(sarr, var);
	if (idx != -1)
	{
		parts = ft_strbrk(sarr[idx], ft_chrpos(sarr[idx], '=', 0) + 1);
		if (parts[1])
			value = ft_strdup(parts[1]);
		else
			value = ft_strdup("");
		ft_sarrfree(&parts);
		return (value);
	}
	else
		return (NULL);
}

char	*ft_var_value(void *ptr, char *var_name)
{
	t_shell	*mns;
	char	*temp;
	char	*value;

	mns = ptr;
	if (!ft_strncmp(var_name, "?\0", 2))
		return (ft_itoa(mns->lstatus));
	temp = ft_strjoin(var_name, "=");
	value = get_var_value(mns->env, temp);
	if (value)
	{
		free (temp);
		return (value);
	}
	value = get_var_value(mns->vars, temp);
	free (temp);
	if (value)
		return (value);
	else
		return (ft_strdup(""));
}
