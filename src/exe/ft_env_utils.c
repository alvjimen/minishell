/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:08:36 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/23 20:08:38 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"

int	ft_valid_identifier(char *str)
{
	if (!str)
		return (0);
	if (ft_isdigit(str[0]))
	{
		ft_printf("export: %s: not a valid identifier\n", str);
		return (0);
	}
	return (1);
}

int	ft_isdefined(t_shell *mns, char *str)
{
	if (ft_chrpos(str, '=', 0) != -1)
	{
		update_all(mns, str);
		clean_exp(mns, str);
		return (1);
	}
	return (0);
}

int	ft_equaleval(char **sarr, char *str)
{
	char	*temp;
	int		idx;

	idx = -1;
	temp = ft_strjoin(str, "=");
	idx = ft_sarrcmp(sarr, temp);
	free (temp);
	return (idx);
}
