/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sarrsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:49:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/31 12:27:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_sarrsort(char **sarr)
{
	size_t	sort_pos;
	size_t	index;
	size_t	cmp;
	size_t	size_sa;
	char	*tmp;

	if (!sarr || !*sarr)
		return ;
	size_sa = ft_sarrsize(sarr);
	index = 0;
	while (index < size_sa)
	{
		sort_pos = 0;
		cmp = 0;
		while (cmp < size_sa)
		{
			if (ft_strncmp(sarr[index], sarr[cmp], ft_strlen(sarr[cmp])) > 0)
				sort_pos++;
			cmp++;
		}
		ft_swap((void **)&sarr[sort_pos], (void **)&sarr[index]);
		index++;
	}
}
