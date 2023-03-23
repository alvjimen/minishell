/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_varname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:48:29 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/23 19:25:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	*ft_var_chars(t_lxr	*lxr)
{
	char *str;

	while (ft_isalnum(lxr->str[lxr->pos + lxr->counter])
			|| lxr->str[lxr->pos + lxr->counter] == '_')
		lxr->counter++;
	str = ft_substr(lxr->str, lxr->pos, lxr->counter);
	if (!str)
		return (NULL);
	if (VAR)
	{
		ft_putstr_fd("var name: ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("rest str: ", 1);
		ft_putstr_fd(&lxr->str[lxr->pos + lxr->counter], 1);
		ft_putstr_fd("\n", 1);
	}
	return (str);
}

char	*ft_var_one_char(t_lxr *lxr)
{
	char	*str;

	str = ft_substr(lxr->str, lxr->pos, lxr->counter);
	if (!str)
		return (NULL);
	if (VAR)
	{
		ft_putstr_fd("var name: ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("rest str: ", 1);
		ft_putstr_fd(&lxr->str[lxr->pos + lxr->counter], 1);
		ft_putstr_fd("\n", 1);
	}
	return (str);
}

char	*ft_get_varname(t_lxr *lxr)
{
	char	*str;

	lxr->counter = 1;
	if (ft_isalpha(lxr->str[lxr->pos + lxr->counter])
		|| lxr->str[lxr->pos + lxr->counter] == '_')
		return (ft_var_chars(lxr));
	else if (ft_isdigit(lxr->str[lxr->pos + lxr->counter]) ||
			lxr->str[lxr->pos + lxr->counter] == '?')
		return (ft_var_one_char(lxr));
	return (lxr->str);
}
