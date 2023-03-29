/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:28:56 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/29 19:38:16 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cmn.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	num_bytes;
	size_t	counter;

	pointer = NULL;
	if (size && (ULONG_MAX / size) < count)
		return (pointer);
	num_bytes = count * size;
	pointer = malloc(num_bytes);
	counter = 0;
	if (!pointer)
		return (pointer);
	while (counter < num_bytes)
		pointer[counter++] = '\0';
	return (pointer);
}
