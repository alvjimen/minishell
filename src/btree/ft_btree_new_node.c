/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:27:24 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/25 16:51:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "btree.h"

t_btree	*ft_btree_new_node(void *content)
{
	t_btree	*tnode;

	tnode = malloc(sizeof(t_btree));
	if (!tnode)
		return (NULL);
	tnode->content = content;
	tnode->left = NULL;
	tnode->right = NULL;
	return (tnode);
}
