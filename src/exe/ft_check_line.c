/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:09:23 by jvasquez          #+#    #+#             */
/*   Updated: 2023/09/17 11:09:25 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

// Search in the line for buildin functions, if theres any
// return 0 to avoid the use of other programs.
int	ft_check_build(t_shell *mns, t_tkn *cont)
{
	if (!ft_strncmp(cont->value, "env\0", 4))
		return (ft_sarrprint(mns->env));
	else if (!ft_strncmp(cont->value, "echo\0", 5))
		return (ft_echo(cont));
	else if (!ft_strncmp(cont->value, "export\0", 7))
		return (ft_export(cont, mns));
	else if (!ft_strncmp(cont->value, "unset\0", 6))
		return (ft_unset(cont, mns));
	else if (!ft_strncmp(cont->value, "cd\0", 3))
		return (ft_cd(cont->str[1]));
	else if (!ft_strncmp(cont->value, "pwd\0", 4))
		return (ft_pwd());
	else if (!ft_strncmp(cont->value, "exit\0", 5))
		exit(EXIT_SUCCESS);
	return (0);
}

// Check if the command exist.
char	*ft_cmd_search(char **paths, char *cmd)
{
	char	*command;
	int		i;

	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		command = ft_strjoin(paths[i++], cmd);
		if (access(command, X_OK) != -1)
			return (command);
		free (command);
	}
	return (NULL);
}

// If there's no built-in, it tries to run a command.
int	ft_check_command(t_shell *mns, t_tkn *cont)
{
	char	*cmd;

	cmd = ft_cmd_search(mns->path, cont->value);
	if (cmd)
	{
		mns->lstatus = 0;
		if (mns->pid)
			mns->pid = fork();
		if (!mns->pid)
		{
			execve(cmd, cont->str, NULL);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		waitpid(mns->pid, &mns->lstatus, 0);
	}
	else
		mns->lstatus = 1;
	return (1);
}

// Revisa la línea en busqueda de built-ins o comandos.
void	ft_check_line(t_shell *mns, t_tkn *cont)
{
	if (!ft_check_build(mns, cont))
		ft_check_command(mns, cont);
}
