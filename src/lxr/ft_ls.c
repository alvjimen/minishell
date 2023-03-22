/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/22 18:50:56 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
opendir, readdir, closedir
*/
/*
void	ft_lst_del(void *ptr)
{
	free(ptr);
}
*/

char	**ft_ls(char *str)
{
	DIR				*dir;
	struct dirent	*file;
	char			**files;

	dir = opendir(str);
	files = NULL;
	if (!dir)
		return (NULL);
	file = 1;
	while (file)
	{
		file = readdir(dir);
		if (!file && errno)
		{
			perror("readdir");
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
			counter++;
		}
		files = ft_sarradd(files, file->d_name);
		if (!files)
		{
			free(tmp);
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
	}
	if (closedir(dir) == -1)
	{
		perror("closedir");
		return (NULL);
	}
	return (files);
}
