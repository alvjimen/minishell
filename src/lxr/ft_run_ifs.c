/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_ifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:48:17 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

size_t	ft_run_ifs(t_lxr *lxr)
{
	size_t	counter;

	counter = 0;
	while (lxr->str[lxr->pos + counter] == ' '
		|| lxr->str[lxr->pos + counter] == '\t'
		|| lxr->str[lxr->pos + counter] == '\n')
		counter++;
	return (counter);
}
