/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/18 19:15:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	t_btree	*root;

	while (argc && argv)
	{
		str = readline("> ");
		if (!str)
			return (FAILURE);
		root = ft_btree_builder(str);
		free(str);
		if (!root)
			return (FAILURE);
		ft_expand_vars_regex_unquote(&root);
		ft_print_btree(root);
		ft_btree_clear(&root, ft_destroy_tkn);
	}
	return (SUCCESS);
}
