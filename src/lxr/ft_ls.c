/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:35:03 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/27 19:31:19 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
	TODO got a flag for dir for the caller now to save the dir_name
	and dir_name + '/'
*/

/*
	printf("file_name: %s\n", file->d_name);
	to add the string should be malloc if not issues
	sarradd malloc then no issue
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
	errno = 0;
	while (file)
	{
		file = readdir(dir);
		if (!file && !errno)
			break ;
		if (!file)
		{
			perror("readdir");
			if (closedir(dir) == -1)
				perror("closedir");
			return (NULL);
		}
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
	/*
	 * This is for avoid leaks i should remove it the same with the return value
	 */
	ft_sarrfree(&files);
	return (files + (size_t) dir);
}
