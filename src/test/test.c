/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:04:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/31 20:52:00 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_tkn	*tkn;
	t_lxr	*lxr;

	if (argc == 1)
		return (1);
	lxr = init_lxr(argv[1]);
	if (!lxr)
		return (2);
	tkn = ft_get_token(lxr);
	if (!tkn)
	{
		free(lxr);
		return (3);
	}
	printf("the command is: %s\n", tkn->value);
	free(tkn->value);
	free(tkn);
	tkn = ft_get_token(lxr);
	if (!tkn)
	{
		free(lxr);
		return (3);
	}
	printf("the arg is: %s\n", tkn->value);
	free(tkn->value);
	free(tkn);
	free(lxr);
	return (0);
}
