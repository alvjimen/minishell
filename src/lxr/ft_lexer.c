/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/19 15:57:36 by alvjimen         ###   ########.fr       */
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

static void	ft_print_tkn(t_tkn *content)
{
	if (content->token == ASSIGNMENT_WORD)
		ft_putstr_fd("Token ASSIGNMENT_WORD:\n", 1);
	else if (content->token == WORD)
		ft_putstr_fd("Token WORD:\n", 1);
	else if (content->token == PARENTHESIS)
		ft_putstr_fd("Token PAREN:\n", 1);
	else if (content->token == ERROR)
		ft_putstr_fd("Token ERROR:\n", 1);
	else if (content->token == AMBIGUOUS)
		ft_putstr_fd("Token AMBIGUOUS:\n", 1);
	else if (content->token == FILENAME)
		ft_putstr_fd("Token FILENAME:\n", 1);
	else if (content->token == HDFILENAME)
		ft_putstr_fd("Token FILENAME:\n", 1);
}

void	ft_print_lst(void	*ptr)
{
	t_tkn	*content;

	if (!ptr)
		return ;
	content = (t_tkn *)ptr;
	if (!content)
		return ;
	ft_print_tkn(content);
	ft_putstr_fd(content->value, 1);
	ft_putstr_fd("\n", 1);
	if (content->str)
	{
		ft_putstr_fd("str\n", 1);
		ft_sarrprint(content->str);
	}
	if (content->regex)
	{
		ft_putstr_fd("regex\n", 1);
		ft_sarrprint(content->regex);
	}
}
