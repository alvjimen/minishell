/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/14 13:50:00 by alvjimen         ###   ########.fr       */
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
		if (argv[1][0] == '-' && argv[1][1] && argv[1][1] == 'c'
				&& argv[1][2] == '\0')
		{
			str = ft_strdup(argv[2]);
			if (!str)
				return (1);
			lxr = ft_init_lxr(str);
			if (!lxr)
			{
				free(str);
				return (-1);
			}
			lxr->mode = NONINTERACTIVE;
			ft_get_tokens(lxr);
			/*ft_token_varname(lxr);*/
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
		if (!lxr)
		{
			free(lxr);
			return (1);
		}
		lxr->mode = NONINTERACTIVE;
		ft_get_tokens(lxr);
		free(lxr->str);
		free(lxr);
	}
	return (0);
}
