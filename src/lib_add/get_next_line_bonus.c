/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:19 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/11 19:59:56 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnl.h"

char	*get_next_line(int fd)
{
	static char		*buff[FD_SETSIZE];
	size_t			n_ch;
	ssize_t			b_count;
	char			*line;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	b_count = BUFFER_SIZE;
	n_ch = 0;
	while (b_count == BUFFER_SIZE || buff[fd])
	{
		line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		b_count = read(fd, line, BUFFER_SIZE);
		line = ft_get_line((void **)&line, &n_ch, &b_count, (void **)&buff[fd]);
		if (line)
			return (line);
	}
	return (NULL);
}

void	*ft_get_line(void **line, size_t *n_chr, ssize_t *b_count, void **buff)
{
	void	*tmp_line;
	ssize_t	ncl;

	if (*buff)
		*n_chr = ft_strlen(*buff);
	tmp_line = ft_memjoin_free(buff, line, n_chr, b_count);
	ncl = (ssize_t)((char *)ft_memchr(*buff, '\n', *n_chr) - (char *)*buff) + 1;
	if (ncl != ((ssize_t)(*buff) * -1) + 1)
	{
		tmp_line = ft_calloc(sizeof(char), ncl + 1);
		ft_memmove(tmp_line, *buff, ncl);
		*n_chr -= ncl;
		*line = ft_calloc(sizeof(char), (*n_chr + 1));
		ft_memmove(*line, ((char *)(*buff) + ncl), *n_chr);
		free(*buff);
		*buff = *line;
		return (tmp_line);
	}
	if (*b_count != BUFFER_SIZE && *buff)
	{
		tmp_line = *buff;
		*buff = NULL;
		return (tmp_line);
	}
	return (NULL);
}
