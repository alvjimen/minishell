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
#include <termios.h>

/*
*	Checkpoint para debug
*/
void	checkpoint(t_shell *mns, t_tkn *cont, char *accion)
{
	if (DEBUG)
	{
		if (mns->pid && !mns->child)
			printf("---Padre---\n%s\npid: %u\nvalue: %s\nop: %d\n\n",
				accion, mns->pid, cont->value, cont->operators);
		else
			printf("---Hijo %d---\n%s\npid: %u\nvalue: %s\nop: %d\n\n",
				mns->child, accion, mns->pid, cont->value, cont->operators);
	}
}

void	redirect(t_btree *root, t_shell *mns, t_tkn *cont)
{
	if (cont->operators == PIPE)
		ft_to_pipe(root, mns);
	else if (cont->operators == GREATER || cont->operators == DGREATER)
		ft_to_file(root, cont, mns);
	else if (cont->operators == LOWER)
		ft_from_file(root, mns);
	else if (cont->operators == DLOWER)
		ft_from_heredoc(root, mns);
}

int	ft_isredirection(int op)
{
	return (op >= PIPE && op <= DLOWER);
}

void	executer(t_btree *root, t_shell *mns, int child)
{
	t_tkn	*cont;

	if (!root)
		exit(EXIT_SUCCESS);
	cont = (t_tkn *)root->content;
	checkpoint(mns, cont, "exe");
	if (ft_isredirection(cont->operators))
		redirect(root, mns, cont);
	else if (ft_iscondition(cont->operators))
		contition(root, mns, cont);
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
		init_signals();
		str = readline("mns> ");
		if (sign_stt)
			continue ;
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
			//ft_print_btree(mns.root);
			ft_expand_vars_regex_unquote(&mns.root, &mns);
			//ft_print_btree(mns.root);
			mns.lstatus = -1;
			mns.pstatus = 0;
			mns.pid = 1;
			mns.im = NULL;
			mns.child = 0;
			mns.output = ft_strdup("-");
			executer(mns.root, &mns, 0);
			free (mns.output);
			ft_btree_clear(&mns.root, ft_destroy_tkn);
		}
	}
	system("leaks -q test");
	return (SUCCESS);
}
