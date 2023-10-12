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

#include "lxr.h"
#include "mns.h"
#include <stdio.h>
#include <termios.h>

/*Checkpoint para debug*/
/*void	checkpoint(t_shell *mns, t_tkn *cont, char *accion)
{
	char	*info;

	if (0)
		return ;
	if (mns->pid && !mns->child)
		info = ft_strjoin("\n---Padre---\n", accion);
	else
		info = ft_strjoin("\n---Hijo---\n", accion);
	info = ft_strjoinfree(
			ft_strjoinfree(info, "\nChild: ", 0),
			ft_strjoinfree(ft_itoa(mns->child),
				ft_strjoin("\nValue: ",
					ft_strjoin(cont->value, "\n")), 2), 2);
	info = ft_strjoinfree(info, "Op: ", 0);
	info = ft_strjoinfree(info, ft_itoa(cont->operators), 2);
	info = ft_strjoinfree(info, "\nLeft ", 0);
	if (mns->root->left)
		info = ft_strjoinfree(info,
				((t_tkn *)mns->root->left->content)->value, 0);
	info = ft_strjoinfree(info, "\nRight ", 0);
	if (mns->root->right)
		info = ft_strjoinfree(info,
				((t_tkn *)mns->root->right->content)->value, 0);
	ft_putstr_fd(info, 2);
	free(info);
}*/

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

	// checkpoint(mns, cont, "Exe");
void	executer(t_btree *root, t_shell *mns, int child)
{
	t_tkn	*cont;

	(void)child;
	if (!root)
		exit(EXIT_SUCCESS);
	mns->root = root;
	cont = (t_tkn *)root->content;
	if (root->left
		&& ((t_tkn *)root->left->content)->token >= ERROR)
		ft_printf("%s\n", "error");
	else if (root->right
		&& ((t_tkn *)root->right->content)->token >= ERROR)
		ft_printf("%s\n", "error");
	else if (ft_isredirection(cont->operators))
		redirect(root, mns, cont);
	else if (ft_iscondition(cont->operators))
		contition(root, mns, cont);
	else
		ft_check_line(mns, cont);
	if (child)
		exit(EXIT_SUCCESS);
}

void	send_exe(t_btree *tree, t_shell *mns)
{
	ft_expand_vars_regex_unquote(&tree, mns);
	mns->lstatus = -1;
	mns->pid = 1;
	mns->child = 0;
	executer(tree, mns, 0);
	ft_btree_clear(&tree, ft_destroy_tkn);
}

//Change the NULL ptr to the pointer of your choose
//Modify the file src/lxr/ft_dollar_expansion.c line 16 with your
//var_expansion_fun
//ft_print_btree(tree);
int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_shell	mns;
	t_btree	*tree;

	init_minishell(&mns, envp);
	while (argc && argv)
	{
		init_signals();
		str = readline("mns> ");
		if (g_sign_stt)
		{
			free(str);
			continue ;
		}
		if (!str)
			return (FAILURE);
		tree = ft_btree_builder(str);
		add_history(str);
		free(str);
		if (tree)
			send_exe(tree, &mns);
		system("leaks mini_shell");
	}
	system("leaks -q test");
	return (SUCCESS);
}
