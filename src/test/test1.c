/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/06 18:11:56 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	t_btree	*root;
	char	**words;

	if (argc >= 3 && argv[1][0] == '-' && argv[1][1] && argv[1][1] == 'c'
		&& argv[1][2] == '\0')
	{
		str = ft_strdup(argv[2]);
		if (!str)
			return (FAILURE);
		root = ft_btree_builder(str);
		free(str);
		if (!root)
			return (FAILURE);
		words = ft_get_array_words(&root);
		if (words)
		{
			ft_sarrprint(words);
			ft_sarrfree(&words);
		}
		ft_btree_clear(&root, ft_destroy_tkn);
		return (SUCCESS);
	}
	return (SUCCESS);
}
