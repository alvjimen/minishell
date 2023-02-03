/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:51:06 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:55:24 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include	<unistd.h>
# include	<fcntl.h>
# include	"cmn.h"
# include	"str.h"
# include	"mem.h"

char	*get_next_line(int fd);
void	*ft_memjoin(void const *s1, void const *s2, size_t l_s1, ssize_t l_s2);
void	*ft_get_line(void **line, size_t *n_chr, ssize_t *b_count, void **buff);
void	*ft_memjoin_free(void **buff, void **line, size_t *n_chr, ssize_t *b_c);
# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif
#endif
