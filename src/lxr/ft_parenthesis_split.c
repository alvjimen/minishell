/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthesis_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:09:01 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/21 08:53:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
	return value Status
	0				ALL OK.
	1				Paremeter error
	2				Syntax error.
	3				Malloc error
*/
int	ft_parenthesis_split(char	*str, t_btree **root)
{
	size_t	len;
	char	*tmp;
	t_lxr	*lxr;

	if (!str || !root || !*root)
		return (1);/* ERROR ON PARAMETER*/
	len = ft_strlen(str);
	if (len < 2)
		return (2);/*Syntax error*/
	tmp = ft_substr(str, 1, len - 2);
	if (!tmp)
		return (3);/*Malloc error*/
	lxr = ft_init_lxr(tmp);
	if (!lxr)
	{
		free(tmp);
		return (3);
	}
	len = ft_get_more_input(lxr);
	if (len == NO_TOKEN)
	{
		free(lxr);
		free(tmp);
		return (2);
	}
	else if (len == 1)
	{
		free(lxr);
		free(tmp);
		return (3);
	}
	len = ft_operators_split(&lxr->btree);
	if (len == 1)
		return (1);
	ft_destroy_tkn(root->content);
	*root = lxr->btree;
	return (0);
}
