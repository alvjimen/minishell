/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:41:00 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/28 18:41:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_io_number(t_lxr *lxr)
{
	if (ft_isdigit(lxr->str[lxr->pos]))
	{
		if (lxr->str[lxr->pos + 1] == '>')
		{
			printf("io number find %d\n", lxr->str[lxr->pos]);
			lxr->pos++;
			ft_token_greater(lxr);
		}
		else if (lxr->str[lxr->pos + 1] == '<')
		{
			printf("io number find %d\n", lxr->str[lxr->pos]);
			lxr->pos++;
			ft_token_lower(lxr);
		}
		else
			lxr->pos ++;
	}
}

void	ft_token_greater(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '>')
	{
		printf("Greater find\n");
		if (lxr->str[lxr->pos + 1] == '>')
		{
			printf("DGreater find\n");
			lxr->pos++;
		}
		lxr->pos ++;
	}
}

void	ft_token_lower(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '<')
	{
		if (lxr->str[lxr->pos + 1] == '<')
		{
			printf("DLower find\n");
			lxr->pos++;
		}
		printf("Lower find\n");
		lxr->pos++;
	}
}