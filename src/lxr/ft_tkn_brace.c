/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:31:17 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/01 11:31:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_lbrace(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '{')
	{
		printf("Close Parentesis find\n");
		lxr->pos++;
	}
}

void	ft_token_rbrace(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '}')
	{
		printf("Close Parentesis find\n");
		lxr->pos++;
	}
}
