/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:13:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/15 11:43:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	**ft_lst_to_sarr(t_list *node)
{
	char	**words;
	t_tkn	*content;
	size_t	counter;

	words = NULL;
	while (node)
	{
		content = node->content;
		node = node->next;
		if (!content)
			continue ;
		if (content->regex)
		{
			counter = 0;
			while (content->regex[counter])
			{
				words = ft_sarradd(words, content->regex[counter]);
				if (!words)
					return (NULL);
				counter++;
			}
		}
		else
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
	if (ft_tokens_assignment_word(root[0]->content) == SUCCESS)
	{
		node = ft_split_list((t_list **)root, ft_tokens_word);
		if (node)
		{
			ft_lstclear((t_list **)root, ft_destroy_tkn);
			root[0] = (t_btree *)node;
		}
	}
	if (ft_tokens_assignment_word(root[0]->content) == SUCCESS
		|| ft_tokens_word(root[0]->content) == SUCCESS)
	{
		words = ft_lst_to_sarr((t_list *) root[0]);
		ft_lstclear((t_list **)&root[0]->right, ft_destroy_tkn);
	}
	return (words);
}

void	ft_get_array_words_recursively(void **ptr)
{
	t_btree	**root;
	t_tkn	*content;
	char	**words;

	root = (t_btree **)ptr;
	if (!root)
		return ;
	words = ft_get_array_words(root);
	if (!root[0])
	{
		ft_sarrfree(&words);
		return ;
	}
	content = root[0]->content;
	if (!content)
	{
		ft_sarrfree(&words);
		return ;
	}
	content->str = words;
}
