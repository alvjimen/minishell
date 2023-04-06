/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/06 22:08:45 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include "str.h"
#include "cmn.h"

t_lxr	*ft_init_lxr(char *s)
{
	t_lxr	*lxr;

	lxr = ft_calloc(1, sizeof(t_lxr));
	if (!lxr)
		return (NULL);
	lxr->str = s;
	return (lxr);
}

void	ft_print_lst(void	*ptr)
{
	t_tkn	*content;

	if (!ptr)
		return ;
	content = (t_tkn *)ptr;
	if (content->token == ASSIGNMENT_WORD)
		ft_putstr_fd("Token ASSIGNMENT_WORD:\n", 1);
	else if (content->token == WORD)
		ft_putstr_fd("Token WORD:\n", 1);
	else if (content->token == PARENTHESIS)
		ft_putstr_fd("Token PAREN:\n", 1);
	ft_putstr_fd(content->value, 1);
	ft_putstr_fd("\n", 1);
	if (content->str)
	{
		ft_putstr_fd("sarrprint\n", 1);
		ft_sarrprint(content->str);
	}
}
