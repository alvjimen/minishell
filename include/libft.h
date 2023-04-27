	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   libft.h                                            :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2022/06/14 12:18:46 by alvjimen          #+#    #+#             */
	/*   Updated: 2022/09/27 15:20:05 by alvjimen         ###   ########.fr       */
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
#endif
