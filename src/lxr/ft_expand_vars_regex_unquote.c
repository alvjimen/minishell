/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_vars_regex_unquote.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:07:27 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 14:42:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_expand_vars_regex_unquote(t_btree **root, void *param)
{
	ft_btree_apply_to_node_pointer_infix_param(root, param,
		ft_unquote_quotes_regex_recursively);
	ft_btree_apply_to_node_pointer_infix(root,
		ft_get_array_words_recursively);
}
