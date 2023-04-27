/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:02:33 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/17 20:02:59 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lxr.h"

void	ft_print_btree(t_btree *root)
{
	if (!root)
		return ;
	ft_putstr_fd("printing\n", 1);
	ft_btree_apply_prefix(root, ft_print_lst);
}
