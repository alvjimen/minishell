/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_paren.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:34:26 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/01 11:44:38 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_lparen(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '(')
	{
		if (lxr->str[lxr->pos + 1] == '(')
		{
			printf("Open Double Parentesis find\n");
			lxr->pos++;
		}
		else
			printf("Open Parentesis find\n");
		lxr->pos++;
	}
}

void	ft_token_rparen(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == ')' && tokens->quotes & DQUOTES | I_STATE))
	{
		if (lxr->str[lxr->pos + 1] == ')' && tokens->quotes & DQUOTES | I_STATE)
		{
			printf("Close Double Parentesis find\n");
			lxr->pos++;
		}
		else
			printf("Close Parentesis find\n");
		lxr->pos++;
	}
}
