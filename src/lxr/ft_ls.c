/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/07 22:01:20 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	if (ft_strncmp(file->d_name, ".", 2) == 0 ||
	   ft_strncmp(file->d_name, "..", 3) == 0)
		   continue ;
 */

char	**ft_ls(char *str)
{
	DIR				*dir;
	struct dirent	*file;
	char			**files;

	dir = opendir(str);
	if (!dir)
		return (NULL);
	files = NULL;
	file = (struct dirent *)1;
	str = NULL;
	errno = 0;
	while (file)
	{
		file = readdir(dir);
		if (!file && !errno)
			break ;
		else if (!file)
		{
			perror("readdir");
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		files = ft_sarradd(files, file->d_name);
		if (!files)
		{
			ft_sarrfree(&files);
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		if (file->d_type == 0x4)
		{
			str = ft_strjoin(file->d_name, "/");
			if (!str)
			{
				ft_sarrfree(&files);
				return (NULL);
			}
			files = ft_sarradd(files, str);
			if (!files)
			{
				ft_sarrfree(&files);
				free(str);
				if (closedir(dir) == -1)
					perror("closedir");
				return (NULL);
			}
			free(str);
			str = NULL;
		}
	}
	if (closedir(dir) == -1)
	{
		perror("closedir");
		return (NULL);
	}
	free(str);
	ft_sarrsort(files);
	/*
	ft_sarrprint(files);
	 * This is for avoid leaks i should remove it the same with the return value
	ft_sarrfree(&files);
	 */
	return (files);
}
