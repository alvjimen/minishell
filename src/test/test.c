/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/04 09:30:50 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	char	**words;
	t_lxr	*lxr;

	lxr = NULL;
	if (argc >= 3 && argv[1][0] == '-' && argv[1][1] && argv[1][1] == 'c'
		&& argv[1][2] == '\0')
	{
		str = ft_strdup(argv[2]);
		if (!str)
			return (FAILURE);
		lxr = ft_init_lxr(str);
		if (!lxr)
		{
			free(str);
			return (FAILURE);
		}
		words = ft_ls(".");
		words = NULL;
		lxr->mode = NONINTERACTIVE;
		ft_get_tokens(lxr);
		if (ft_syntax_analizer(lxr->btree, lxr) == FAILURE)
		{
			ft_putstr_fd("Syntax ERROR\n", 2);
			return (FAILURE);
		}
		ft_lstiter((t_list *)lxr->btree, ft_print_lst);
		if (argc == 4)
		{
			free(str);
			str = ft_vars_expansion(ft_strdup(argv[3]));
			if (str)
			{
				ft_putstr_fd("vars_expansion return: ", 1);
				ft_putstr_fd(str, 1);
				ft_putstr_fd("\n", 1);
			}
		}
		if (argc > 4 && argc <= 6)
		{
			ft_putstr_fd("operators split\n", 1);
			ft_operators_split(&lxr->btree);
			ft_btree_apply_prefix(lxr->btree, ft_print_lst);
			if (ft_regex(argv[3], argv[4]) == SUCCESS)
				ft_putstr_fd("Match\n", 1);
		}
		if (argc > 6)
		{
			ft_putstr_fd("operators recursive split\n", 1);
			ft_btree_apply_to_node_pointer_infix(&lxr->btree, ft_operators_split_recursively);
			ft_btree_apply_prefix(lxr->btree, ft_print_lst);
		}
		if (argc > 5)
		{
			words = ft_get_array_words(&lxr->btree);
			ft_putstr_fd("get_array_words content\n", 1);
			ft_sarrprint(words);
			ft_putstr_fd("get_array_words content sorted\n", 1);
			ft_sarrsort(words);
			ft_sarrprint(words);
			ft_sarrfree(&words);
		}
		ft_btree_clear(&lxr->btree, ft_destroy_tkn);
		free(lxr);
		free(str);
		return (SUCCESS);
	}
	while (1)
	{
		str = readline("> ");
		if (!str)
			return (FAILURE);
		lxr = ft_init_lxr(str);
		if (!lxr)
		{
			free(lxr);
			return (FAILURE);
		}
		lxr->mode = NONINTERACTIVE;
		ft_get_tokens(lxr);
		if (ft_syntax_analizer(lxr->btree, lxr) == FAILURE)
		{
			ft_putstr_fd("Syntax ERROR\n", 2);
			return (FAILURE);
		}
		free(lxr->str);
		free(lxr);
	}
	return (SUCCESS);
}
