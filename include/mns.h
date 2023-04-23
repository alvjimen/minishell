/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mns.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:19:31 by jvasquez          #+#    #+#             */
/*   Updated: 2023/01/18 23:19:47 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNS_H
# define MNS_H

# include "lxr.h"
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/wait.h>

typedef struct s_shell
{
	t_btree				*root;
	char				**path;
	char				**env;
	char				*output;
	int					waiting;
	int					cpipe;
	struct sigaction	s_action;
}	t_shell;

typedef struct s_child
{
	pid_t	pid;
	int		fd[2];
	int		status;
}	t_child;

void	init_minishell(t_shell *mns, char **envp);
char	**ft_get_path(char **envp);

void	ft_echo(t_tkn	*content);
int		ft_export(char *line, t_shell *mns);
int		ft_unset(char *line, t_shell *mns);

char	**ft_update_env(char *item, t_shell *mns);

#endif
