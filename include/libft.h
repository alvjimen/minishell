/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:18:46 by alvjimen          #+#    #+#             */
/*   Updated: 2023/06/21 18:15:26 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "cmn.h"
# include "str.h"
# include "mem.h"
# include "num.h"
# include "out.h"
# include "lst.h"
# include "dct.h"
# include "err.h"
# include "prt.h"
# include "gnl.h"
# include "lst.h"
# include "sarr.h"

char	**ft_split_chars(char const *s, char *delim);
void	ft_swap(void **ptr1, void **ptr2);
char	*ft_strjoinfree(char *s1, char *s2, int which);
char	**ft_strbrk(char *str, int b_point);
int		ft_chrpos(char *str, int chr, int start);
char	*ft_strget_btwn(char *str, int start, char ini, char end);
char	*ft_strrep(char *str, char *old, char *new);
char	*ft_strstr(char *str, char *to_find);

int		ft_aredigit(char *str);
#endif
