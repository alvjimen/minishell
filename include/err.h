/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:50:02 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:50:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ERR_H
# define ERR_H
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include "out.h"

void	ft_check_malloc(void *pointer);
void	ft_check_fork(pid_t *child, size_t num_cmd);
void	ft_check_access(int access);
void	ft_check_open(int fd);
void	ft_check_pipe(int pipe);
void	ft_check_env(char *env);
void	ft_check_dup(int i);
#endif
