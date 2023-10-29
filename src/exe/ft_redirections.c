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

void	forkways(t_btree *root, t_shell *mns)
{
	if (mns->child == 1111)
		executer(root->left, mns, mns->child);
	if (mns->child == 2222)
		executer(root->right, mns, mns->child);
}

void	ft_to_pipe(t_btree *root, t_shell *mns)
{
	if (mns->child == 1111 || mns->child == 2222)
		mns->child = 1;
	pipe(mns->fd);
	mns->pid = fork();
	if (!mns->pid)
	{
		mns->child = 1111;
		dup2(mns->fd[STDOUT_FILENO], STDOUT_FILENO);
	}
	else
	{
		mns->pid = fork();
		if (!mns->pid)
		{
			mns->child = 2222;
			dup2(mns->fd[STDIN_FILENO], STDIN_FILENO);
		}
	}
	close(mns->fd[STDOUT_FILENO]);
	close(mns->fd[STDIN_FILENO]);
	forkways(root, mns);
	wait(&mns->lstatus);
	wait(&mns->lstatus);
	if (!mns->pid || mns->child)
		exit (EXIT_SUCCESS);
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
		close(fd);
		executer(root->left, mns, mns->child++);
		exit(EXIT_SUCCESS);
	}
	waitpid(mns->pid, &mns->lstatus, 0);
}

void	ft_from_file(t_btree *root, t_shell *mns)
{
	char	*filename;
	int		fd;

	mns->pid = fork();
	if (!mns->pid)
	{
		filename = ((t_tkn *)root->right->content)->value;
		fd = open(filename, O_RDONLY, 0644);
		if (fd == -1)
			exit(EXIT_FAILURE);
		dup2(fd, STDIN_FILENO);
		close(fd);
		mns->child = 1;
		executer(root->left, mns, ++mns->child);
		exit(EXIT_SUCCESS);
	}
	waitpid(mns->pid, &mns->lstatus, 0);
}

void	ft_from_heredoc(t_btree *root)
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
	((t_tkn *)root->content)->operators = LOWER;
}
