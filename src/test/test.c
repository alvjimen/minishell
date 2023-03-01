/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/01 19:47:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	t_lxr	*lxr;

	lxr = NULL;
	while (1)
	{
		str = readline("> ");
		if (!str)
			return (1);
		lxr = ft_init_lxr(str);
		ft_token_varname(lxr);
		free(str);
		free(lxr);
	}
	return (0);
}
