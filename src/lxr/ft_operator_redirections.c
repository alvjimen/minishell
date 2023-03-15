/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:46:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/15 06:43:52 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_greater(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] != '>')
		return (NOT_TOKEN);
	if (lxr->str[lxr->pos + 1] == '>')
	{
		ft_putstr_fd("DGreater find\n", 1);
		lxr->pos++;
	}
	else
		ft_putstr_fd("Greater find\n", 1);
	lxr->pos ++;
	return (0);
}

int	ft_token_lower(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] != '<')
		return (NOT_TOKEN);
	if (lxr->str[lxr->pos + 1] == '<')
	{
		ft_putstr_fd("DLower find\n", 1);
		lxr->pos++;
	}
	else
		ft_putstr_fd("Lower find\n", 1);
	lxr->pos++;
	return (0);
}
