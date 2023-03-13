/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_more_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:29:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 19:15:52 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
Return values.
	1 some got wrong
	0 all good
*/
int	ft_get_more_input(t_lxr *lxr)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(lxr->str, "\n");
	if (!str)
		return (1);
	free(lxr->str);
	lxr->str = str;
	tmp = readline("> ");
	if (!tmp)
		return (1);
	str = ft_strjoin(lxr->str, tmp);
	free(lxr->str);
	lxr->str = NULL;
	free(tmp);
	tmp = NULL;
	lxr->str = str;
	if (!str)
		return (1);
	return (0);
}
