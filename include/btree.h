/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:32:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/22 18:46:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H
# include <stdlib.h>

typedef struct s_btree
{
	void			*content;
	struct s_btree	*right;
	struct s_btree	*left;
}	t_btree;

t_btree	*ft_btree_new_node(void *content);
void	ft_btree_apply_postfixfix(t_btree *root, void (*applyf)(void *));
void	ft_btree_apply_infixfix(t_btree *root, void (*applyf)(void *));
void	ft_btree_apply_postfixfix(t_btree *root, void (*applyf)(void *));
void	ft_btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void*));
int		ft_btree_level_count(t_btree *root);	
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
				int current_level, int is_first_elem));
void	ft_btree_add_left(t_btree *root, t_btree *node);
void	ft_btree_add_right(t_btree *root, t_btree *node);
void	ft_btree_add_parent(t_btree **root, t_btree *node,
			void (*f)(t_btree *, t_btree *));
void	ft_btree_apply_to_node_infix(t_btree *root, void (*applyf)(void *));
void	ft_btree_swap(void *ptr);
#endif
