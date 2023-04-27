/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:53:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 09:36:53 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	*ft_previous_var(t_lxr **lxr, t_vars *vars)
{
	vars->value = ft_var_value(NULL, vars->name);
	free(vars->name);
	vars->name = NULL;
	if (!vars->value)
	{
		free(*lxr);
		return (NULL);
	}
	vars->tmp = ft_substr(lxr[0]->str, 0, lxr[0]->pos);
	if (!vars->tmp)
	{
		free(vars->value);
		free(*lxr);
		return (NULL);
	}
	return (vars->tmp);
}

	/*Join the previos var with the value of the var*/
static char	*ft_join_previos_with_var_value(t_lxr **lxr, t_vars *vars)
{
	vars->name = ft_strjoin(vars->tmp, vars->value);
	free(vars->tmp);
	vars->tmp = NULL;
	free(vars->value);
	vars->value = NULL;
	if (!vars->name)
	{
		free(*lxr);
		return (NULL);
	}
	vars->tmp = vars->name;
	if (VAR)
	{
		ft_putstr_fd("join prev + var: ", 1);
		ft_putstr_fd(vars->tmp, 1);
		ft_putstr_fd("\n", 1);
	}
	return (vars->name);
}

/*Get the after var with the value of the var*/
static char	*ft_after_var(t_lxr **lxr, t_vars *vars)
{
	char	*aux;

	vars->name = NULL;
	aux = lxr[0]->str + lxr[0]->pos + lxr[0]->counter;
	vars->value = ft_substr(lxr[0]->str, lxr[0]->pos + lxr[0]->counter,
			ft_strlen(aux));
	if (!vars->value)
	{
		free(vars->tmp);
		vars->tmp = NULL;
		free(lxr[0]);
		*lxr = NULL;
		return (NULL);
	}
	if (VAR)
	{
		ft_putstr_fd("after var: ", 1);
		ft_putstr_fd(vars->value, 1);
		ft_putstr_fd("\n", 1);
	}
	return (vars->value);
}

/*Join the previos var with the value of the var*/
static char	*ft_join_str(t_lxr **lxr, t_vars *vars)
{
	vars->name = ft_strjoin(vars->tmp, vars->value);
	free(vars->tmp);
	free(vars->value);
	vars->tmp = NULL;
	vars->value = NULL;
	if (!vars->name)
	{
		free(lxr[0]);
		return (NULL);
	}
	if (VAR)
	{
		ft_putstr_fd("join of all the token: ", 1);
		ft_putstr_fd(vars->name, 1);
		ft_putstr_fd("\n", 1);
	}
	return (vars->name);
}

char	*ft_dollar_expansion(t_lxr **lxr, t_vars *vars)
{
	vars->name = ft_get_varname(*lxr);
	if (!vars->name)
		return (lxr[0]->str);
	else if (vars->tmp == lxr[0]->str)
	{
		free(vars->name);
		lxr[0]->pos++;
		return (lxr[0]->str);
	}
	if (ft_previous_var(lxr, vars) == NULL)
		return (NULL);
	if (ft_join_previos_with_var_value(lxr, vars) == NULL)
		return (NULL);
	if (ft_after_var(lxr, vars) == NULL)
		return (NULL);
	if (ft_join_str(lxr, vars) == NULL)
		return (NULL);
	lxr[0]->str = vars->name;
	vars->name = NULL;
	lxr[0]->pos = -1;
	lxr[0]->counter = 0;
	return (lxr[0]->str);
}
