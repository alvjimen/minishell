/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:09:23 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/23 13:21:54 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

int	ft_exit_status(t_tkn *cont)
{
	if (cont->str[1] && ft_aredigit(cont->str[1]))
		exit(ft_atoi(cont->str[1]));
	else if (cont->str[1])
	{
		ft_printf("exit: %s: numeric argument required\n", cont->str[1]);
		exit(255);
	}
	exit(EXIT_SUCCESS);
}

/*	Search in the line for buildin functions, if theres any
	return 0 to avoid the use of other programs.
	if (!ft_strncmp(cont->value, "var\0", 4))
		return (ft_sarrprint(mns->vars));*/
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
		return (ft_cd(cont->str[1], mns));
	else if (!ft_strncmp(cont->value, "pwd\0", 4))
		return (ft_pwd());
	else if (ft_chrpos(cont->value, '=', 0) != -1)
		return (ft_isvar(mns, cont));
	else if (!ft_strncmp(cont->value, "exit\0", 5))
		ft_exit_status(cont);
	return (-1);
}

// Check if the command exist.
char	*ft_cmd_search(char **paths, char *cmd)
{
	char	*command;
	int		i;

	if (!paths)
		return (NULL);
	i = 0;
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
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

	mns->lstatus = 0;
	cmd = ft_cmd_search(mns->path, cont->value);
	if (mns->pid)
		mns->pid = fork();
	if (!mns->pid)
	{
		execve(cmd, cont->str, mns->env);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	free (cmd);
	do_sigign(SIGINT);
	do_sigign(SIGQUIT);
	wait(&mns->lstatus);
	if (WIFEXITED(mns->lstatus))
		mns->lstatus = WEXITSTATUS(mns->lstatus);
	init_signals();
	return (1);
}

// Revisa la línea en busqueda de built-ins o comandos.
void	ft_check_line(t_shell *mns, t_tkn *cont)
{
	mns->lstatus = 0;
	mns->lstatus = ft_check_build(mns, cont);
	if (mns->lstatus == -1)
		ft_check_command(mns, cont);
}
