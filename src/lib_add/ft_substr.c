/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:27:03 by alvjimen          #+#    #+#             */
/*   Updated: 2022/09/22 17:25:16 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	num;

	num = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(str))
		len = ft_strlen(str) - start;
	aux = ft_calloc(sizeof(char), (len + 1));
	if (!aux)
		return (NULL);
	while (num < len)
	{
		aux[num] = str[start + num];
		num++;
	}
	return (aux);
}
