/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/21 19:28:43 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
opendir, readdir, closedir
*/
void	ft_lst_del(void *ptr)
{
	free(ptr);
}

char **ft_ls(char *str)
{
	DIR				*dir;
	struct dirent	*file;
	t_list			*lst;
	char			*filename;
	t_list			*node;

	counter = 0;
	dir = opendir(str);
	tmp = NULL;
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
		size = counter + 1;
		tmp = ft_calloc(counter + 1, sizeof(char *));
		if (!tmp)
		{
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		filename = ft_strdup(file->d_name);
		if (!str)
		{
			free(tmp);
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		node = ft_lstnew(filename);
		if (!node)
		{
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
		ft_lstadd_back(&lst, node);
	}
	if (closedir(dir) == -1)
	{
		ft_lstclear(lst
		perror("closedir");
		return (NULL);
	}
	return (files);
}
