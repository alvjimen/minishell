/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/18 14:48:18 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	t_btree	*root;

	if (argc > 1)
	{
		root = ft_btree_builder(argv[1]);
		if (!root)
			return (FAILURE);
		ft_expand_vars_regex_unquote(&root, (void *)0x1);
		ft_print_btree(root);
		ft_btree_clear(&root, ft_destroy_tkn);
		#ifdef __APPLE__
			system("leaks -q test");
		#endif
		return (SUCCESS);
	}
	while (argc && argv)
	{
		str = readline("> ");
		if (!str)
			return (FAILURE);
		root = ft_btree_builder(str);
		free(str);
		#ifdef __APPLE__
			system("leaks -q test");
		#endif
		if (!root)
			return (FAILURE);
		ft_expand_vars_regex_unquote(&root, (void *)0x1);
		ft_print_btree(root);
		ft_btree_destroy(&root);
	}
	return (SUCCESS);
}
