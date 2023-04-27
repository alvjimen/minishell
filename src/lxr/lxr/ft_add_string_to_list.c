/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_string_to_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:00:09 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/22 17:47:09 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	*ft_add_string_to_list(t_lxr *lxr, size_t counter)
{
	lxr->tokens.value = ft_substr(lxr->str, lxr->pos, counter);
	if (!lxr->tokens.value)
	{
		lxr->tokens.token = NO_TOKEN;
		lxr->tokens.operators = NONE;
		ft_putstr_fd("Error on malloc of string\n", 1);
		return (NULL);
	}
	lxr->pos += counter;
	lxr->num_tokens++;
	return (lxr->tokens.value);
}
