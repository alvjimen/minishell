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
	mns->vars = NULL;
	mns->exp = ft_sarrcpy(envp);
	mns->env = ft_sarrcpy(envp);
	mns->path = ft_get_path(mns->env);
}
