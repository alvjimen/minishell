/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_vars_regex_unquote.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:07:27 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/17 18:08:40 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_expand_vars_regex_unquote(t_btree **root)
{

	ft_btree_apply_to_node_pointer_infix(root,
		ft_unquote_quotes_regex_recursively);
	ft_btree_apply_to_node_pointer_infix(root,
		ft_get_array_words_recursively);
}
