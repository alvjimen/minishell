/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:46:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 19:17:07 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_greater(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] != '>')
		return (NOT_TOKEN);
	if (lxr->str[lxr->pos + 1] == '>')
	{
		printf("DGreater find\n");
		lxr->pos++;
	}
	else
		printf("Greater find\n");
	lxr->pos ++;
	return (0);
}

int	ft_token_lower(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] != '<')
		return (NOT_TOKEN);
	if (lxr->str[lxr->pos + 1] == '<')
	{
		printf("DLower find\n");
		lxr->pos++;
	}
	else
		printf("Lower find\n");
	lxr->pos++;
	return (0);
}
