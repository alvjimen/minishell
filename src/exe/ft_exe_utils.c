/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:00:36 by jvasquez          #+#    #+#             */
/*   Updated: 2023/10/27 13:24:26 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>

/** Encuentra un nombre de archivo disponible para heredoc */
char	*ft_hdname(void)
{
	char	*filename;
	int		n;

	filename = ft_strdup(".hdtmp");
	n = 0;
	while (!access(filename, 0))
		filename = ft_strjoinfree(".hdtmp", ft_itoa(n++), 1);
	return (filename);
}

/** Imprime un archivo por pantalla */
void	ft_printfile(char *filename)
{
	int		fd;
	char	*line;

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

/*
 * Ejecuta los heredocs del árbol.
*/
void	prexe(t_btree *root)
{
	t_tkn	*cont;

	cont = (t_tkn *)root->content;
	if (cont->operators == DLOWER)
		ft_from_heredoc(root);
	if (root->left)
		prexe(root->left);
	if (root->right)
		prexe(root->right);
}

/*
 * Prepara las variables y expande antes de iniciar el executer.
*/
void	send_exe(t_btree *tree, t_shell *mns)
{
	ft_expand_vars_regex_unquote(&tree, mns);
	if (!tree)
		return ;
	mns->lstatus = 0;
	mns->pid = 1;
	mns->child = 0;
	prexe(tree);
	executer(tree, mns, 0);
	ft_btree_clear(&tree, ft_destroy_tkn);
}
