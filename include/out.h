/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:52:23 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 18:27:02 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUT_H
# define OUT_H
# include "str.h"
# include <unistd.h>
# include <limits.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base_unsigned_fd(size_t nbr, char *base, int fd);
void	ft_putnbr_base_fd(int nbr, char *base, int fd);
void	ft_putpointer_fd(size_t pointer, int fd);
#endif
