/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:07:25 by jvasquez          #+#    #+#             */
/*   Updated: 2023/06/21 18:26:10 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mns.h"
#include <stdio.h>

/*
*	Checkpoint para debug
*/
void	checkpoint(t_shell *mns, t_tkn *cont, char *accion)
{
	if (DEBUG) {
		if (mns->pid)
			printf("---Padre---\n%s\npid: %u\nlstatus: <%d>\npstatus: <%d>\nvalue: %s\noutput: %s\n\n",
				accion, mns->pid, mns->lstatus, mns->pstatus, cont->value, mns->output);
		else
			printf("---Hijo---\n%s\npid: %u\nlstatus: <%d>\npstatus: <%d>\nvalue: %s\noutput: %s\n\n",
				accion, mns->pid, mns->lstatus, mns->pstatus, cont->value, mns->output);
	}
}

void	ft_mns_btree_inorder(t_btree *root,
	void (*f)(t_shell *, t_tkn *), t_shell *mns)
{
	if (!root)
		return ;
	f(mns, (t_tkn *)root->content);
	ft_mns_btree_inorder(root->left, f, mns);
	ft_mns_btree_inorder(root->right, f, mns);
}

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
	checkpoint(mns, cont, "entra a Check cmd");
	cmd = ft_cmd_search(mns->path, cont->value);
	if (cmd)
	{
		mns->lstatus = 1;
		if (mns->pid)
			mns->pid = fork();
		if (!mns->pid)
		{
			checkpoint(mns, cont, "exe cmd");
			execve(cmd, cont->str, NULL);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		waitpid(mns->pid, &mns->lstatus, 0);
	}
	else
		mns->lstatus = 0;
	checkpoint(mns, cont, "sale de Check cmd");
	return (1);
}

// Añade el operador a la cola de salida.
void	ft_queue(t_shell *mns, t_tkn *cont, int op)
{
	char	*s;

	(void) cont;
	s = ft_substr("AOPgGlL", op - 1, 1);
	if (!mns->output)
		mns->output = ft_strdup(s);
	else
		mns->output = ft_strjoinfree(mns->output, s, 0);
	free (s);
}

// Revisa la línea en busqueda de built-ins o comandos.
void	ft_check_line(t_shell *mns, t_tkn *cont)
{
	checkpoint(mns, cont, "sale de Check cmd");
	if (!ft_check_build(mns, cont))
		ft_check_command(mns, cont);
}

// Pop the char at given point from a string.
char *ft_popchar(char *str, size_t pos)
{
	char	*tmp;

	if (pos > ft_strlen(str) || pos < 0)
		return (str);
	if (!pos)
		tmp = ft_substr(str, 1, ft_strlen(str) - 1);
	else if (pos == ft_strlen(str) - 1)
		tmp = ft_substr(str, 0, ft_strlen(str) - 2);
	else
		tmp = ft_strjoinfree(ft_substr(str, 0, pos),
				ft_substr(str, pos + 1, ft_strlen(str) - 1), 2);
	free (str);
	return (tmp);
}

void	redirectedFork(t_shell *mns, t_tkn *cont, int fd)
{
	mns->pid = fork();
	if (!mns->pid)
	{
		dup2(mns->fd[fd], fd);
		ft_check_line(mns, cont);
		exit (EXIT_SUCCESS);
	}
	if (fd >= 0 && fd <= 1)
		close(mns->fd[fd]);
}

// This child will write on a pipe.
void	sender(t_shell *mns, t_tkn *cont)
{
	pipe(mns->fd);
	redirectedFork(mns, cont, STDOUT_FILENO);
	mns->pstatus = 2;
}

// This child will read from a pipe.
void	reciever(t_shell *mns, t_tkn *cont)
{
	checkpoint(mns, cont, "at reciever");
	if (mns->output[ft_strlen(mns->output) - 1] == 'g')
	{
		mns->pid = fork();
		if (!mns->pid)
		{
			checkpoint(mns, cont, "hijo en Reciever");
			// dup2(mns->fd[0], STDIN_FILENO);
			mns->holded_value = ft_strdup(cont->value);
			mns->holded_contstr = ft_sarrcpy(cont->str);
			mns->lstatus = 2;
			mns->pstatus = 0;
			mns->output = ft_popchar(mns->output, ft_strlen(mns->output) - 2);
			return ;
			// dup2(open(cont->value, O_CREAT | O_WRONLY, 0644), STDOUT_FILENO);
			/* ft_sarrfree(&cont->str);
			cont->str = ft_sarrcpy(mns->holded_contstr);
			free (cont->value);
			cont->value = mns->holded_value;
			ft_check_line(mns, cont); */
			// exit(EXIT_SUCCESS);
		}
		else
			mns->output = ft_popchar(mns->output, ft_strlen(mns->output) - 2);
	}
	else
		redirectedFork(mns, cont, STDIN_FILENO);
	waitpid(mns->pid, &mns->pstatus, 0);
	mns->output = ft_popchar(mns->output, 1);
	mns->pstatus = 0;
	mns->lstatus = 1;
}

// This child will read from active pipe and then will write on the next pipe.
void both(t_shell *mns, t_tkn *cont)
{
	int	oldpipe[2];

	oldpipe[0] = mns->fd[0];
	pipe(mns->fd);
	mns->pid = fork();
	if (mns->pid == 0)
	{
		dup2(oldpipe[0], STDIN_FILENO);
		dup2(mns->fd[1], STDOUT_FILENO);
		ft_check_line(mns, cont);
		exit (EXIT_SUCCESS);
	}
	close(oldpipe[0]);
	close(mns->fd[1]);
	mns->output = ft_popchar(mns->output, 1);
	mns->pstatus = 2;
	mns->lstatus = 1;
}

void	ft_change_output(t_shell *mns, t_tkn *cont)
{
	if (mns->output[ft_strlen(mns->output) - 2] == 'P' && mns->output[ft_strlen(mns->output) - 1] == 'P')
		mns->pstatus = 3;
	if (mns->pstatus == 1)
		sender(mns, cont);
	else if (mns->pstatus == 2)
		reciever(mns, cont);
	else if (mns->pstatus == 3)
		both(mns, cont);
}

void	ft_printfile(char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_lredir(t_shell *mns, t_tkn *cont)
{
	checkpoint(mns, cont, "l");
	if (mns->lstatus == -1)
	{
		pipe(mns->fd);
		redirectedFork(mns, cont, STDIN_FILENO);
	}
	else
	{
		mns->pid = fork();
		if (!mns->pid)
		{
			dup2(mns->fd[1], STDOUT_FILENO);
			ft_printfile(cont->value);
			exit(EXIT_SUCCESS);
		}
		mns->lstatus = 1;
	}
	if (mns->pid && mns->lstatus == 1)
	{
		close(mns->fd[0]);
		close(mns->fd[1]);
		waitpid(mns->pid, &mns->pstatus, 0);
	}
	mns->lstatus = 1;
	checkpoint(mns, cont, "Sale");
}

/* ft_writefile(char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_CREAT | O_WRONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
} */

void	ft_gredir(t_shell *mns, t_tkn *cont)
{
	checkpoint(mns, cont, "gredir");
	if (mns->lstatus == -1)
	{
		mns->pid = fork();
		if (!mns->pid)
		{
			mns->holded_value = ft_strdup(cont->value);
			mns->holded_contstr = ft_sarrcpy(cont->str);
		}
	}
	else if (mns->lstatus == 1 && !mns->pid)
	{
		checkpoint(mns, cont, "Deploy gredir");
		dup2(open(cont->value, O_CREAT | O_WRONLY, 0644), STDOUT_FILENO);
		ft_sarrfree(&cont->str);
		cont->str = ft_sarrcpy(mns->holded_contstr);
		free (cont->value);
		cont->value = mns->holded_value;
		ft_check_line(mns, cont);
		exit(EXIT_SUCCESS);
	}
	if (mns->pid && mns->lstatus == 1)
		waitpid(mns->pid, &mns->pstatus, 0);
	mns->lstatus = 1;
	checkpoint(mns, cont, "Sale g");
}

/*
	Función a ejecutar en cada nodo,
	si el nodo contiene un operador, se añade a la cola de salida
	en caso contrario ejecuta según el output anterior y el operador
	siguiente.
*/
void	ft_exe(t_shell *mns, t_tkn *cont)
{
	checkpoint(mns, cont, "exe");
	if (!mns ||!cont)
		return ;
	if (cont->operators == PIPE)
			mns->pstatus = 1;
	if (mns->pstatus && !cont->operators)
		ft_change_output(mns, cont);
	if (cont->operators)
		ft_queue(mns, cont, cont->operators);
	else if (mns->output[1] == 'l')
		ft_lredir(mns, cont);
	else if (mns->output[1] == 'g')
		ft_gredir(mns, cont);
	else if (mns->lstatus == -1 && !mns->pstatus)
		ft_check_line(mns, cont);
	else if (!mns->pstatus)
	{
		if ((mns->output[1] == 'A' && !mns->lstatus) ||
			(mns->output[1] == 'O' && mns->lstatus))
		{
			ft_check_line(mns, cont);
			mns->output = ft_popchar(mns->output, 1);
		}
		else if (mns->output[1] == 'P')
			mns->output = ft_popchar(mns->output, 1);
	}
}

void	executer(t_btree *root, t_shell *mns, int child)
{
	t_tkn *cont;

	if (!root)
		exit(EXIT_SUCCESS);
	cont = (t_tkn *)root->content;
	printf("%s\n", cont->value);
	if (cont->operators == PIPE)
	{
		pipe(mns->fd);
		mns->pid = fork();
		if (!mns->pid)
			dup2(mns->fd[STDOUT_FILENO], STDOUT_FILENO);
		close(mns->fd[STDOUT_FILENO]);
		if (!mns->pid)
			executer(root->left, mns, 1);
		mns->pid = fork();
		if (!mns->pid)
			dup2(mns->fd[STDIN_FILENO], STDIN_FILENO);
		close(mns->fd[STDIN_FILENO]);
		if (!mns->pid)
			executer(root->right, mns, 1);
		waitpid(mns->pid, &mns->lstatus, 0);
	}
	else if (cont->operators == AND_IF)
	{
		executer(root->left, mns, 0);
		executer(root->right, mns, 0);
	}
	else
		ft_check_line(mns, cont);
	if (child)
		exit(EXIT_SUCCESS);
}

int	main (int argc, char **argv, char **envp)
{
	char	*str;
	t_shell	mns;

	init_minishell(&mns, envp);
	while (argc && argv)
	{
		str = readline("mns> ");
		if (!str)
			return (FAILURE);
		mns.root = ft_btree_builder(str);
		add_history(str);
		free(str);
		if (mns.root)
		{
			//Change the NULL ptr to the pointer of your choose
			//Modify the file src/lxr/ft_dollar_expansion.c line 16 with your
			//var_expansion_fun
			ft_expand_vars_regex_unquote(&mns.root, &mns);
			// ft_print_btree(mns.root);
			mns.lstatus = -1;
			mns.pstatus = 0;
			mns.pid = 1;
			mns.im = NULL;
			mns.output = ft_strdup("-");
			// ft_mns_btree_inorder(mns.root, ft_exe, &mns);
			executer(mns.root, &mns, 0);
			free (mns.output);
			ft_btree_clear(&mns.root, ft_destroy_tkn);
		}
	}
	system("leaks -q test");
	return (SUCCESS);
}
