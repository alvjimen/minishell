/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:07:25 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/23 17:08:09 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

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
		ft_echo(cont);
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
	if (ft_cmd_search(mns->path, cont->value))
	{
		mns->lstatus = 1;
		// printf("Existe cmd: %s\n", cont->value);
	}
	else
	{
		mns->lstatus = 0;
		// printf("No existe cmd: %s\n", cont->value);
	}
	return (1);
}

/*void	ft_rem_output(t_shell *mns, char *c)
{
	ft_add_output(mns, "&");
}*/

// Añade el operador a la cola de salida.
void	ft_queue(t_shell *mns, t_tkn *cont, int op)
{
	(void) cont;
	char	*s;

	s = ft_substr("AOPgGlL", op - 1, 1);
	if (!mns->output)
		mns->output = ft_strdup(s);
	else
		mns->output = ft_strjoinfree(mns->output, s, 0);
	free (s);
	// printf("output: %s\nop: %d\n", mns->output, op);
}

// Revisa la línea en busqueda de built-ins o comandos.
void	ft_check_line(t_shell *mns, t_tkn *cont)
{
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

/*
	Función a ejecutar en cada nodo,
	si el nodo contiene un operador, se añade a la cola de salida
	en caso contrario ejecuta según el output anterior y el operador
	siguiente.
*/
void	ft_exe(t_shell *mns, t_tkn *cont)
{
	if (!mns ||!cont)
		return ;
	if (cont->operators)
		ft_queue(mns, cont, cont->operators);
	else if (mns->lstatus == -1)
		ft_check_line(mns, cont);
	else
	{
		if ((mns->output[1] == 'A' && mns->lstatus) ||
			(mns->output[1] == 'O' && !mns->lstatus))
		{
			ft_check_line(mns, cont);
			mns->output = ft_popchar(mns->output, 1);
		}
		else
			mns->output = ft_popchar(mns->output, 1);
	}
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
			ft_expand_vars_regex_unquote(&mns.root);
			// ft_print_btree(mns.root);
			mns.lstatus = -1;
			mns.output = ft_strdup("-");
			ft_mns_btree_inorder(mns.root, ft_exe, &mns);
			free (mns.output);
			ft_btree_clear(&mns.root, ft_destroy_tkn);
		}
	}
	system("leaks -q test");
	return (SUCCESS);
}
