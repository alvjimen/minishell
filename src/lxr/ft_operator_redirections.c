/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:46:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 19:00:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_greater(t_lxr *lxr)
{
	size_t	counter;

	if (lxr->str[lxr->pos] != '>')
		return (NOT_TOKEN);
	counter = 1;
	lxr->tokens.token = OPERATOR;
	if (lxr->str[lxr->pos + counter] == '>')
	{
		lxr->tokens.operators = DGREATER;
		counter++;
	}
	else
		lxr->tokens.operators = GREATER;
	if (ft_add_string_to_list(lxr, counter) == NULL)
		return (NOT_TOKEN);
	return (SUCCESS);
}

int	ft_token_lower(t_lxr *lxr)
{
	size_t	counter;

	if (lxr->str[lxr->pos] != '<')
		return (NOT_TOKEN);
	counter = 1;
	if (lxr->str[lxr->pos + counter] == '<')
	{
		counter++;
		lxr->tokens.operators = DLOWER;
	}
	else
		lxr->tokens.operators = LOWER;
	if (ft_add_string_to_list(lxr, counter) == NULL)
		return (NOT_TOKEN);
	return (SUCCESS);
}
