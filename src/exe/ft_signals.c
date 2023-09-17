/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:28:53 by jvasquez          #+#    #+#             */
/*   Updated: 2023/09/17 21:28:54 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"
#include <stdio.h>
#include <termios.h>

void	signal_silence(void)
{
	struct termios		term_attr;

	if (tcgetattr(STDIN_FILENO, &term_attr) < 0)
	{
		perror("tcgetattr");
		exit(1);
	}
	term_attr.c_lflag &= ~VEOF;
	term_attr.c_lflag &= ~ECHOCTL;
	term_attr.c_lflag &= ~NOFLSH;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term_attr) < 0)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	signal_handler(int sig, siginfo_t *si, void *uap)
{
	(void)si;
	(void)uap;

	if (sig == SIGINT)
		init_signals();
	else if (sig == SIGQUIT)
		init_signals();
	return ;
}

int	init_signals(void)
{
	struct sigaction	signal;

	signal.sa_flags = SA_RESTART;
	signal.sa_sigaction = signal_handler;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
	signal_silence();
	return (EXIT_SUCCESS);
}

void	do_sigign(int signum)
{
	struct sigaction	signal;

	signal.sa_handler = SIG_IGN;
	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	if (sigaction(signum, &signal, NULL) < 0)
		exit(EXIT_FAILURE);
}
