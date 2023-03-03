/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/03 13:10:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

/*
	ft_token_varname(lxr);
*/
int	main(int argc, char *argv[])
{
	char	*str;
	t_lxr	*lxr;

	lxr = NULL;
	if (argc >= 3)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
		{
			lxr = ft_init_lxr(argv[2]);
			ft_token_varname(lxr);
			free(lxr);
			return (0);
		}
		else
			return (-1);
	}
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
