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

// Built-in echo.
int	ft_echo(t_tkn	*content)
{
	int	i;

	i = 0;
	if (!content->str[1])
	{
		printf("\n");
		return (0);
	}
	if (!ft_strncmp(content->str[1], "-n", 2))
		i++;
	while (content->str[++i])
		printf("%s ", content->str[i]);
	if (ft_strncmp(content->str[1], "-n", 2))
		printf("\n");
	return (0);
}
