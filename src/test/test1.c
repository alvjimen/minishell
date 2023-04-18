/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/18 13:58:01 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	t_btree	*root;
	char	**words;

	if (argc == 2)
	{
		t_lxr		*lxr;
		t_quotes	*quotes;
		char		**words;

		lxr = ft_init_lxr(argv[1]);
		if (!lxr)
			return (FAILURE);
		quotes = ft_init_quotes(lxr);
		free(lxr);
		if (!quotes)
			return (FAILURE);
		words = ft_regex_quotes(quotes);
		ft_destroy_quotes(&quotes);
		if (!words)
			return (FAILURE);
		ft_sarrfree(&words);
	}
	else if (argc > 3)
	{
		str = ft_strdup(argv[2]);
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
