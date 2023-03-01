/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:37 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/28 18:35:34 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_bquotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '`')
	{
		printf("` finded\n");
		lxr->pos++;
	}
}

void	ft_token_squotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '\'')
	{
		printf("' finded\n");
		lxr->pos++;
	}
}

void	ft_token_dquotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '"')
	{
		printf("\" finded\n");
		lxr->pos++;
	}
}
