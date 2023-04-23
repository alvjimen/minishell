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

int	ft_cd(char *dir)
{
	chdir(dir + 3);
	getcwd(NULL, 0);
	return (1);
}

// Search in the line for buildin functions, if theres any
// return 0 to avoid the use of other programs.
int	ft_check_line(t_shell *mns, t_tkn *cont)
{
	if (!ft_strncmp(cont->value, "env\0", 4))
		return (ft_sarrprint(mns->env));
	else if (!ft_strncmp(cont->value, "echo\0", 5))
		ft_echo(cont);
	else if (!ft_strncmp(cont->value, "export\0", 7))
		return (ft_export(cont->value, mns));
	else if (!ft_strncmp(cont->value, "cd ", 3))
		return (ft_cd(cont->value));
	else if (!ft_strncmp(cont->value, "exit\0", 5))
		exit(EXIT_SUCCESS);
	return (0);
}

void	ft_exe(t_shell *mns, t_tkn *cont)
{
	if (!mns ||!cont)
		return ;
	ft_check_line(mns, cont);
}

int	main (int argc, char **argv, char **envp)
{
	char	*str;
	t_shell	mns;

	init_minishell(&mns, envp);
	while (argc && argv)
	{
		str = readline("> ");
		if (!str)
			return (FAILURE);
		mns.root = ft_btree_builder(str);
		add_history(str);
		free(str);
		if (mns.root)
		{
			ft_expand_vars_regex_unquote(&mns.root);
			ft_print_btree(mns.root);
			ft_mns_btree_inorder(mns.root, ft_exe, &mns);
			ft_btree_clear(&mns.root, ft_destroy_tkn);
		}
	}
	system("leaks -q test");
	return (SUCCESS);
}
