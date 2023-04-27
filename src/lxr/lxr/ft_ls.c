/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/19 20:23:52 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	ft_loop
*/
static char	**ft_close_ls(DIR *dir)
{
	if (closedir(dir) == -1)
		perror("closedir");
	return (NULL);
}

static char	**ft_error_handle(char **sarr, DIR *dir)
{
	ft_sarrfree(&sarr);
	perror("readdir");
	return (ft_close_ls(dir));
}

static char	**ft_add_slash_dir(struct dirent *file, char **files, DIR *dir)
{
	char	*str;

	str = NULL;
	if (file && file->d_type == 0x4)
	{
		str = ft_strjoin(file->d_name, "/");
		if (!str)
		{
			ft_sarrfree(&files);
			return (ft_close_ls(dir));
		}
		files = ft_sarradd(files, str);
		if (!files)
		{
			ft_sarrfree(&files);
			free(str);
			return (ft_close_ls(dir));
		}
		free(str);
	}
	return (files);
}

static char	**ft_loop(DIR	*dir, struct dirent *file)
{
	char	**files;

	files = NULL;
	while (file)
	{
		file = readdir(dir);
		if (!file && !errno)
			break ;
		else if (!file)
			return ((char **)ft_error_handle(files, dir));
		files = ft_sarradd(files, file->d_name);
		if (!files)
			return (ft_close_ls(dir));
		files = ft_add_slash_dir(file, files, dir);
		if (!files)
			return (ft_close_ls(dir));
	}
	return (files);
}

char	**ft_ls(char *str)
{
	DIR				*dir;
	struct dirent	*file;
	char			**files;

	dir = opendir(str);
	if (!dir)
		return (NULL);
	file = (struct dirent *)1;
	errno = 0;
	files = ft_loop(dir, file);
	if (!files)
		return (NULL);
	if (closedir(dir) == -1)
	{
		ft_sarrfree(&files);
		perror("closedir");
		return (NULL);
	}
	ft_sarrsort(files);
	return (files);
}
