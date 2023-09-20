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

#define DEBUG 0

int	sign_stt;

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
	int					signal;
	pid_t				pid;
	int					fd[2];
	int					redirfd;
	int					child;
	struct sigaction	s_action;
	char				*im;
	char				*holded_value;
	char				**holded_contstr;
}	t_shell;

typedef struct s_child
{
	pid_t	pid;
	int		fd[2];
}	t_child;

void	checkpoint(t_shell *mns, t_tkn *cont, char *accion);
void	executer(t_btree *root, t_shell *mns, int child);
void	redirect(t_btree *root, t_shell *mns, t_tkn *cont);

// Check line
int		ft_check_build(t_shell *mns, t_tkn *cont);
char	*ft_cmd_search(char **paths, char *cmd);
int		ft_check_command(t_shell *mns, t_tkn *cont);
void	ft_check_line(t_shell *mns, t_tkn *cont);


// Conditions
int		ft_iscondition(int op);
void	contition(t_btree *root, t_shell *mns, t_tkn *cont);

// Exe utils
char	*ft_hdname(void);
void	ft_printfile(char *filename);

// To | From Redirections
void	ft_to_pipe(t_btree *root, t_shell *mns);
void	ft_from_file(t_btree *root, t_shell *mns);
void	ft_to_file(t_btree *root, t_tkn *cont, t_shell *mns);
void	ft_from_heredoc(t_btree *root, t_shell *mns);

// Signals
void	signal_silence(void);
void	signal_handler(int sig, siginfo_t *si, void *uap);
int		init_signals(void);
void	do_sigign(int signum);


// Old main
void	init_minishell(t_shell *mns, char **envp);
char	**ft_get_path(char **envp);
int		ft_cd(char *dir);
int		ft_pwd(void);

int		ft_echo(t_tkn	*content);
int		ft_export(t_tkn *cont, t_shell *mns);
int		ft_unset(t_tkn *cont, t_shell *mns);

char	**ft_update_env(char *item, t_shell *mns);

#endif
