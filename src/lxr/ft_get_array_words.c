/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:13:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/01 11:54:47 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	**ft_lst_to_sarr(t_list *node)
{
	char	**words;
	t_tkn	*content;

	words = NULL;
	while (node)
	{
		content = node->content;
		node = node->next;
		if (!content)
			continue ;
		words = ft_sarradd(words, content->value);
		if (!words)
			return (NULL);
	}
	return (words);
}

char	**ft_get_array_words(t_btree **root)
{
	char	**words;
	t_list	*node;

	if (!root || !*root)
		return (NULL);
	words = NULL;
	/*if is some word discard all the varnames this if i think is prescindible*/
	if (!ft_tokens_assignment_word(root[0]->content))
	{
		node = ft_split_list((t_list **)root, ft_tokens_word);
		ft_lstclear((t_list **)root, ft_destroy_tkn);
		root[0] = (t_btree *)node;
	}
	words = ft_lst_to_sarr((t_list *) root[0]);
	return (words);
}
/*
	node = (t_list *)root[0];
	while (node)
	{
		content = node->content;
		node = node->next;
		if (!content)
			continue ;
		words = ft_sarradd(words, content->value);
		if (!words)
			return (NULL);
	}
*/
