/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/26 16:47:58 by alvjimen         ###   ########.fr       */
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
	str = NULL;
	if (!dir)
		return (NULL);
	file = (struct dirent *)1;
	while (file)
	{
		file = readdir(dir);
		if (!file && errno)
		{
			perror("readdir");
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		printf("file_name: %s\n", file->d_name);
		files = ft_sarradd(files, file->d_name);
		if (!files)
		{
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
	ft_sarrfree(files);
	files = NULL;
	return (files);
}
