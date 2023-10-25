/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:36:07 by jvasquez          #+#    #+#             */
/*   Updated: 2023/04/23 20:36:07 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mns.h"

static int	ft_isn(char	*str)
{
	int	i;

	if (!str || str[0] != '-')
		return (0);
	i = 0;
	while (str[i])
		if (str[++i] != 'n')
			return (0);
	return (1);
}

// Built-in echo.
int	ft_echo(t_tkn	*content)
{
	int	i;

	if (!content->str[1])
	{
		printf("\n");
		return (0);
	}
	i = 1;
	while (ft_isn(content->str[i]))
		i++;
	while (content->str[i])
		printf("%s ", content->str[i++]);
	if (!ft_isn(content->str[1]))
		printf("\n");
	return (0);
}
