/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:26:34 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/23 20:26:35 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"

// Recieve env variable and return a list of paths.
char	**ft_get_path(char **envp)
{
	char	**path;
	char	*env;
	size_t	pos;

	if (ft_sarrcmp(envp, "PATH=") == -1)
		return (NULL);
	env = ft_strdup(envp[ft_sarrcmp(envp, "PATH=")]);
	if (!env)
		return (NULL);
	path = ft_split(env, ':');
	free(env);
	if (!path)
		return (NULL);
	env = ft_strdup(*path + 5);
	free(path[0]);
	path[0] = ft_strjoinfree(env, "/", 0);
	pos = 0;
	while (path[++pos])
		path[pos] = ft_strjoinfree(path[pos], "/", 0);
	return (path);
}

// Change currrent directory.
int	ft_cd(char *dir)
{
	chdir(dir);
	return (0);
}

// Get the current directory.
int	ft_pwd(void)
{
	printf("%s\n", getcwd(NULL, 0));
	return (0);
}
