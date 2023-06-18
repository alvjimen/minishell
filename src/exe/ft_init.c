/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:51:40 by jvasquez          #+#    #+#             */
/*   Updated: 2023/02/04 09:51:41 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"

// Initialize the t_shell struct.
void	init_minishell(t_shell *mns, char **envp)
{
	ft_bzero(mns, sizeof(t_shell));
	mns->waiting = 0;
	mns->cpipe = 0;
	// mns->prompt = NULL;
	// mns->prompt = ft_sarradd(mns->prompt, "Mns: ");
	// mns->prompt = ft_sarradd(mns->prompt, "dquote> ");
	// mns->prompt = ft_sarradd(mns->prompt, "quote> ");
	// mns->prompt = ft_sarradd(mns->prompt, "par> ");
	// mns->prompt = ft_sarradd(mns->prompt, "par dquote> ");
	// mns->prompt = ft_sarradd(mns->prompt, "par quote> ");
	// mns->prompt = ft_sarradd(mns->prompt, "pipe> ");
	mns->env = ft_sarrcpy(envp);
	mns->path = ft_get_path(mns->env);
	// mns->s_action.__sigaction_u.__sa_sigaction = handle_sig;
	// mns->s_action.sa_flags = SA_SIGINFO;
	// sigaction(SIGINT, &mns->s_action, 0);
}
