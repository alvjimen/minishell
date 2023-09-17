/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:18:53 by jvasquez          #+#    #+#             */
/*   Updated: 2023/09/17 12:18:54 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

void	ft_to_pipe(t_btree *root, t_shell *mns)
{
	pipe(mns->fd);
	mns->pid = fork();
	if (!mns->pid)
		dup2(mns->fd[STDOUT_FILENO], STDOUT_FILENO);
	close(mns->fd[STDOUT_FILENO]);
	if (!mns->pid)
		executer(root->left, mns, mns->child++);
	mns->pid = fork();
	if (!mns->pid)
		dup2(mns->fd[STDIN_FILENO], STDIN_FILENO);
	close(mns->fd[STDIN_FILENO]);
	if (!mns->pid)
		executer(root->right, mns, mns->child++);
	waitpid(mns->pid, &mns->lstatus, 0);
}

void	ft_to_file(t_btree *root, t_tkn	*cont, t_shell *mns)
{
	int		fd;
	char	*filename;

	mns->pid = fork();
	if (!mns->pid)
	{
		filename = ((t_tkn *)root->right->content)->value;
		if (cont->operators == GREATER)
			fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
			fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
		dup2(fd, STDOUT_FILENO);
		executer(root->left, mns, mns->child++);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	waitpid(mns->pid, &mns->lstatus, 0);
}

void	ft_from_file(t_btree *root, t_shell *mns)
{
	char	*filename;

	pipe(mns->fd);
	mns->pid = fork();
	if (!mns->pid)
	{
		filename = ((t_tkn *)root->right->content)->value;
		dup2(mns->fd[STDOUT_FILENO], STDOUT_FILENO);
		ft_printfile(filename);
		exit(EXIT_SUCCESS);
	}
	close(mns->fd[STDOUT_FILENO]);
	mns->pid = fork();
	if (!mns->pid)
		dup2(mns->fd[STDIN_FILENO], STDIN_FILENO);
	close(mns->fd[STDIN_FILENO]);
	if (!mns->pid)
		executer(root->left, mns, mns->child++);
	waitpid(mns->pid, &mns->lstatus, 0);
}

void	ft_from_heredoc(t_btree *root, t_shell *mns)
{
	int		fd;
	char	*line;
	char	**eof;
	char	*filename;

	eof = &((t_tkn *)root->right->content)->value;
	filename = ft_hdname();
	fd = open(filename, O_CREAT | O_WRONLY, 0644);
	line = readline("heredoc> ");
	while (line && ft_strncmp(line, *eof, ft_strlen(*eof) + 1))
	{
		ft_putstr_fd(ft_strjoinfree(line, "\n", 0), fd);
		line = readline("heredoc> ");
	}
	free (line);
	close(fd);
	free (*eof);
	*eof = filename;
	ft_from_file(root, mns);
}
