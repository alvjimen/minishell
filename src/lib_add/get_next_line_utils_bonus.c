/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:07:03 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/22 17:35:21 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

void	*ft_memjoin_free(void **nsbuf, void **line, size_t *n_chr, ssize_t *b_c)
{
	void	*tmp_mem;

	tmp_mem = ft_memjoin(*nsbuf, *line, *n_chr, *b_c);
	free(*line);
	*line = NULL;
	free(*nsbuf);
	*nsbuf = NULL;
	*nsbuf = tmp_mem;
	*n_chr += *b_c;
	return (tmp_mem);
}

void	*ft_memjoin(void const *s1, void const *s2, size_t l_s1, ssize_t l_s2)
{
	char	*mem;

	if ((!s1 && !s2) || (!l_s2 && !l_s1))
		return (NULL);
	mem = ft_calloc(sizeof(char), l_s2 + l_s1 + 1);
	if (!mem)
		return (NULL);
	if (l_s1)
		ft_memmove(mem, s1, l_s1);
	if (l_s2)
		ft_memmove(mem + l_s1, s2, l_s2);
	return (mem);
}
