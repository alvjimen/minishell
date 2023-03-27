/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/27 19:36:42 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
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
		lxr->mode = NONINTERACTIVE;
		ft_get_tokens(lxr);
		if (ft_syntax_analizer(lxr) == FAILURE)
		{
			ft_putstr_fd("Syntax ERROR\n", 2);
			return (FAILURE);
		}
		ft_lstiter((t_list *)lxr->btree, ft_print_lst);
		if (argc > 4)
		{
			ft_putstr_fd("operators split\n", 2);
			ft_operators_split(&lxr->btree);
			ft_btree_apply_prefix(lxr->btree, ft_print_lst);
			/*
			regex	&&	target
			argv[4]	&&	argv[5]
			*/
			if (ft_regex("*.c", "a.c") == SUCCESS)
				ft_putstr_fd("Match\n", 1);
		}
		ft_btree_clear(&lxr->btree, ft_destroy_tkn);
		free(lxr);
		free(str);
		ft_ls(".");
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
		if (ft_syntax_analizer(lxr) == FAILURE)
		{
			ft_putstr_fd("Syntax ERROR\n", 2);
			return (FAILURE);
		}
		free(lxr->str);
		free(lxr);
	}
	return (SUCCESS);
}
