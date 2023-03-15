/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_redirect_io.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:14:49 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/14 18:43:22 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_token_redirect_io(t_lxr *lxr)
{
	int		result;
	size_t	counter;

	if (lxr->str[lxr->pos] != '>' && lxr->str[lxr->pos] != '<')
		return (1);
	counter = 0;
	if (lxr->str[lxr->pos] == '>')
	{
		result = ft_token_greater(lxr);
		if (result == NOT_TOKEN)
			return (NOT_TOKEN);
	}
	else if (lxr->str[lxr->pos] == '<')
	{
		result = ft_token_lower(lxr);
		if (result == NOT_TOKEN)
			return (NOT_TOKEN);
	}
	lxr->pos += ft_run_ifs(lxr);
	result = ft_token_word(lxr, &counter);
	if (result == NOT_TOKEN)
	{
		ft_putstr_fd("invalid redirection\n", 1);
		return (NOT_TOKEN);
	}
	ft_putstr_fd("valid redirection\n", 1);
	return (0);
}
