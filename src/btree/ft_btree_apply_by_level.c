/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_by_level.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:15:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/25 16:43:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

static void	btree_level_counter(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem), int current_level, int is_first_elem)
{
	if (!root | !applyf)
		return ;
	applyf(root->content, current_level, is_first_elem);
	if (is_first_elem)
		is_first_elem = 0;
	current_level++;
	btree_level_counter(root->left, (*applyf), current_level, is_first_elem);
	btree_level_counter(root->left, (*applyf), current_level, is_first_elem);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem))
{
	if (!root | !applyf)
		return ;
	btree_level_counter(root, (*applyf), 0, 1);
}
