/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:09:20 by jvasquez          #+#    #+#             */
/*   Updated: 2023/09/17 12:09:21 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

int	ft_iscondition(int op)
{
	return (op == AND_IF || op == OR_IF);
}

void	contition(t_btree *root, t_shell *mns, t_tkn *cont)
{
	int	op;

	op = cont->operators;
	if (mns->child)
	{
		mns->pid = fork();
		if (!mns->pid)
			executer(root->left, mns, mns->child);
	}
	else
		executer(root->left, mns, mns->child);
	waitpid(mns->pid, &mns->lstatus, 0);
	if ((op == AND_IF && !mns->lstatus) || (op == OR_IF && mns->lstatus))
		executer(root->right, mns, mns->child);
	if (mns->child)
		exit(mns->lstatus);
}
