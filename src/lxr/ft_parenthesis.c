/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:53:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/12 20:51:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	return 0 OK
	return 1 NOK
*/
/*
 int	ft_parenthesis(t_lxr *lxr)
{
	size_t	counter;

	counter = 0;
	if (lxr->str[lxr->pos] != '(')
		return (0);
	lxr->tokens.states |= PAREN;
	while (lxr->tokens.states & PAREN)
	{
		while (lxr->str[lxr->pos + counter] && lxr->str[lxr->pos + counter] != ')')
		{
			if (ft_char_quotes(lxr->str[lxr->pos + counter]))
				if (ft_quotes(lxr, &counter))
					return (1);
			counter++;
		}
		if (lxr->str[lxr->pos + counter] == ')')
		{
			lxr->tokens.states ^= PAREN;
			ft_putstr_fd("Token PAREN:\n", 1);
			write(1, &lxr->str[lxr->pos], counter + 1);
			write(1, "\n", 1);
			lxr->pos += counter + 1;
			return (0);
		}
		else if (lxr->mode & NONINTERACTIVE || ft_get_more_input(lxr))
			break ;
	}
	return (1);
}
*/
int	ft_parenthesis(t_lxr *lxr)
{
	size_t	counter;
	size_t	counter_par;

	counter = 0;
	counter_par = 0;
	if (lxr->str[lxr->pos] != '(')
		return (0);
	counter++;
	lxr->tokens.states |= PAREN;
	while (lxr->tokens.states & PAREN)
	{
		while (lxr->str[lxr->pos + counter] && (counter_par
			|| !counter_par && lxr->str[lxr->pos + counter] != ')'))
		{
			if (lxr->str[lxr->pos + counter] == '(')
				counter_par++;
			else if (lxr->str[lxr->pos + counter] == ')')
				counter_par--;
			else if (ft_char_quotes(lxr->str[lxr->pos + counter]))
				if (ft_quotes(lxr, &counter))
					return (1);
			counter++;
		}
		if (lxr->str[lxr->pos + counter] == ')')
		{
			lxr->tokens.states ^= PAREN;
			ft_putstr_fd("Token PAREN:\n", 1);
			write(1, &lxr->str[lxr->pos], counter + 1);
			write(1, "\n", 1);
			lxr->pos += counter + 1;
			return (0);
		}
		else if (lxr->mode & NONINTERACTIVE || ft_get_more_input(lxr))
			break ;
	}
	return (1);
}
