/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:01:31 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/25 16:51:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

int	ft_btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = ft_btree_level_count(root->left);
	right = ft_btree_level_count(root->right);
	if (right > left)
		return (right + 1);
	return (left + 1);
}
