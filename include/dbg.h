/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:19:05 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 18:38:49 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_H
# define DBG_H
# define CROSS_THIN "┼"
# define COR_TOP_LEFT "┌"
# define COR_TOP_RIGHT "┐"
# define COR_LOW_LEFT "└"
# define COR_LOW_RIGHT "┘"
# define TABLE_T "┬"
# define TABLE_RT "┴"
# define TABLE_PIPE "│"
# define TABLE_SLASH "─"
# define TABLE_BW_DATA_LEFT "├"
# define TABLE_BW_DATA_RIGHT "┤"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "str.h"
# include "out.h"
# include "cmn.h"

typedef struct s_dbg
{
	int		fd;
	int		num_fields;
	size_t	len;
}	t_dbg;

void	ft_title(char *str, int padding, int fd);
void	ft_headers(int fd, int num_fields, ...);
void	ft_data(int fd, int num_fields, ...);
void	ft_foot(int fd, int num_fields, ...);
void	ft_fill_cell(char *str, size_t times, int fd);
void	ft_draw_border(int fd, size_t len, char *delimiter[2]);
void	ft_draw_all_borders(int fd, int num_fields, size_t len,
			char *delimiter[2]);
void	ft_content(int fd, char *str, int padding, char *delimiter[2]);
void	ft_values(int fd, int num_fields, size_t len, char **data);
size_t	ft_max(size_t param);
void	ft_draw_all_contents(t_dbg stc, char **data, char *delimiter[2]);
void	ft_draw_all_fields(t_dbg stc, char **data, char *delim[4]);
void	ft_values(int fd, int num_fields, size_t len, char **data);
#endif
