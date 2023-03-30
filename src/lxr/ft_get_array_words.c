/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:13:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/30 19:28:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	**ft_get_array_words(t_btree **root)
{
	char	**words;
	t_list	*node;
	t_tkn	*content;

	if (!root)
		return (NULL);
	words = NULL;
	/*if is some word discard all the varnames this if i think is prescindible*/
	node = ft_split_list((t_list **)root, ft_tokens_word);
	ft_lstclear(&node, ft_destroy_tkn);
	node = (t_list *)root[0];
	while (node)
	{
		content = node->content;
		if (!content)
		{
			ft_sarrfree(&words);
			return (NULL);
		}
		words = ft_sarradd(words, content->value);
		if (!words)
			return (NULL);
		node = node->next;
	}
	return (words);
}
