/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_more_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:29:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 12:37:00 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/*
Return values.
	0 some got wrong
	1 all good

	TODO Change prompt depending of the missing character
*/
int	ft_get_more_input(t_lxr *lxr)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(lxr->str, "\n");
	if (!str)
		return (0);
	free(lxr->str);
	lxr->str = str;
	tmp = readline("quote ");
	if (!tmp)
		return (0);
	str = ft_strjoin(lxr->str, tmp);
	free(lxr->str);
	free(tmp);
	lxr->str = str;
	if (!str)
		return (0);
	return (1);
}
