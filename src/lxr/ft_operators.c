/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:07:31 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/06 17:32:22 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_operators(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '|')
		ft_operators(lxr);
	else if (lxr->str[lxr->pos] == '&' && lxr->str[lxr->pos + 1] == '&')
		ft_operators(lxr);
}

void	ft_redirections(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '>')
		ft_redirections(lxr);
	else if (lxr->str[lxr->pos] == '<' && lxr->str[lxr->pos + 1] == '>')
		ft_redirections(lxr);
	else if (lxr->str[lxr->pos] == '<')
		ft_redirections(lxr);
}
