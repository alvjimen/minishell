/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:17:59 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:23:46 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	*ft_start_notstar(char **matched, char *str, size_t *counter)
{
	size_t	len;

	if (!matched || !*matched || !str || !counter)
		return (NULL);
	len = ft_strlen(str);
	if (ft_strnstr(*matched, str, len))
	{
		counter[0]++;
		*matched += len;
		return (*matched);
	}
	return (NULL);
}

int	ft_just_asterisk(char *regex)
{
	size_t	len;

	len = 0;
	if (!regex)
		return (SUCCESS);
	while (regex[len] == '*')
		len++;
	if (regex[len] == '\0')
		return (SUCCESS);
	return (FAILURE);
}
