/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:00:36 by jvasquez          #+#    #+#             */
/*   Updated: 2023/09/17 18:00:38 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

/** Encuentra un nombre de archivo disponible para heredoc */
char	*ft_hdname(void)
{
	char	*filename;
	int		n;

	filename = ft_strdup(".hdtmp");
	n = 0;
	while (!access(filename, 0))
		filename = ft_strjoinfree(filename, ft_itoa(n++), 2);
	return (filename);
}

/** Imprime un archivo por pantalla */
void	ft_printfile(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
