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

typedef enum meta
{
	DOLLAR_BIT,
	PIPE_BIT,
	OREDIR_BIT,
	IREDIR_BIT,
	AND_BIT,
	WILD_BIT,
	ODQUOTE_BIT,
	OQUOTE_BIT,
	OR_BIT,
	ODREDIR_BIT,
	IDREDIR_BIT,
	PAR_BIT,
	IPAR_BIT,
	AAND_BIT
}	t_meta;

typedef struct s_shell
{
	t_btree				*root;
	char				**path;
	char				**env;
	char				*output;
	int					meta;
	int					lstatus;
	int					pstatus;
	int					waiting;
	int					cpipe;
	pid_t				pid;
	int					fd[2];
	int					redirfd;
	struct sigaction	s_action;
	char				*im;
}	t_shell;

typedef struct s_child
{
	pid_t	pid;
	int		fd[2];
}	t_child;

void	init_minishell(t_shell *mns, char **envp);
char	**ft_get_path(char **envp);
int		ft_cd(char *dir);
int		ft_pwd(void);

int		ft_echo(t_tkn	*content);
int		ft_export(t_tkn *cont, t_shell *mns);
int		ft_unset(t_tkn *cont, t_shell *mns);

char	**ft_update_env(char *item, t_shell *mns);

#endif
