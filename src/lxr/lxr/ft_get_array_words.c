/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_array_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:13:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 10:13:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

static char	**ft_lst_to_sarr_regex(char ***words, char **regex)
{
	size_t	counter;

	counter = 0;
	while (regex[counter])
	{
		*words = ft_sarradd(*words, regex[counter]);
		if (!*words)
			return (NULL);
		counter++;
	}
	return (*words);
}

static char	**ft_lst_to_sarr(t_list *node, int *error)
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
		if (content->token == ERROR || content->token == AMBIGUOUS)
			*error = content->token;
		if (content->regex)
			ft_lst_to_sarr_regex(&words, content->regex);
		else
			words = ft_sarradd(words, content->value);
		if (!words)
			return (NULL);
	}
	return (words);
}

static void	ft_delete_all_following_assignment_word(t_btree **root)
{
	t_list	*node;

	node = ft_split_list((t_list **)root, ft_tokens_word);
	if (node)
	{
		ft_lstclear((t_list **)root, ft_destroy_tkn);
		root[0] = (t_btree *)node;
	}
}

char	**ft_get_array_words(t_btree **root)
{
	char	**words;
	int		error;

	if (!root || !*root)
		return (NULL);
	words = NULL;
	error = 0;
	if (ft_tokens_assignment_word(root[0]->content) == SUCCESS)
		ft_delete_all_following_assignment_word(root);
	if (ft_tokens_get_array_words(root[0]->content) == SUCCESS)
	{
		words = ft_lst_to_sarr((t_list *) root[0], &error);
		if (error == AMBIGUOUS || error == ERROR || error == SYNTAX_ERROR)
			((t_tkn *)root[0]->content)->token = error;
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
