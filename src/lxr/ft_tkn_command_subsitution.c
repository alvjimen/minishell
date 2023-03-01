/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_command_subsitution.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:42:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/01 11:33:35 by alvjimen         ###   ########.fr       */
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

void	ft_token_dollar(t_lxr	*lxr)
{
	if (lxr->str[lxr->pos] == '$')
	{
		if (lxr->str[lxr->pos + 1] == '(')
		{
			if (lxr->str[lxr->pos + 2] == '(')
			{
				printf("$(( find\n");
				lxr->pos++;
			}
			else
				printf("$( find\n");
			lxr->pos++;
		}
		else if (lxr->str[lxr->pos + 1] == '{')
			ft_tkn_lbrace(lxr);
		else
			printf("Dollar find\n");
		lxr->pos++;
	}
}
