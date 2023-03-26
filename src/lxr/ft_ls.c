/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/26 18:23:17 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	ls on dir return the dir_name and dir_name + '/'
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
	file = (struct dirent *)1;
	while (file)
	{
		file = readdir(dir);
		if (!file && !errno)
			return (NULL);
		if (!file)
		{
			perror("readdir");
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		//printf("file_name: %s\n", file->d_name);
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
	ft_sarrfree(&files);
	return (files);
}
