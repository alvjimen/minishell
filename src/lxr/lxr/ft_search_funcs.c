/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:58:14 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 15:48:43 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_operators_interpipelines(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && !tokens->found && (tokens->operators == OR_IF
			|| tokens->operators == AND_IF))
		return (SUCCESS);
	return (FAILURE);
}

int	ft_operators_intercmd(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && !tokens->found && tokens->operators == PIPE)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_operators_intracmd(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && !tokens->found && (tokens->operators == DGREATER
			|| tokens->operators == GREATER || tokens->operators == LOWER
			|| tokens->operators == DLOWER))
		return (SUCCESS);
	return (FAILURE);
}

int	ft_tokens_assignment_word(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token == ASSIGNMENT_WORD)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_tokens_word(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token == WORD)
		return (SUCCESS);
	return (FAILURE);
}
