/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_funcs_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:44:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 15:55:37 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_tokens_error(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token == ERROR)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_tokens_ambiguous(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token == AMBIGUOUS)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_tokens_syntax_error(void *ptr)
{
	t_tkn	*tokens;

	if (!ptr)
		return (FAILURE);
	tokens = ptr;
	if (tokens && tokens->token == SYNTAX_ERROR)
		return (SUCCESS);
	return (FAILURE);
}

int	ft_tokens_get_array_words(void *ptr)
{
	if (ft_tokens_assignment_word(ptr) == SUCCESS
		|| ft_tokens_word(ptr) == SUCCESS
		|| ft_tokens_error(ptr) == SUCCESS
		|| ft_tokens_ambiguous(ptr) == SUCCESS
		|| ft_tokens_syntax_error(ptr) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}
