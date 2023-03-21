/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/21 19:43:05 by alvjimen         ###   ########.fr       */
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

char **ft_ls(char *str)
{
	DIR				*dir;
	struct dirent	*file;
	t_list			*lst;
	char			*filename;
	char			**files;

	counter = 0;
	dir = opendir(str);
	files = NULL;
	if (!dir)
		return (NULL);
	file =  0;
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
		if (!str)
		{
			free(tmp);
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
	}
	if (closedir(dir) == -1)
	{
		ft_lstclear(lst
		perror("closedir");
		return (NULL);
	}
	/*!Pdte of create an array with the lst or the array directly*/
	return (files);
}
