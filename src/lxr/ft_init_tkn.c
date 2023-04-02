/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tkn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:12 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/02 21:25:53 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_destroy_2d_array(void **ptr)
{
	size_t	counter;
	char	**str;

	counter = 0;
	str = (char **)ptr;
	if (str == NULL || *str == NULL)
		return ;
	while (str[counter])
	{
		free(str[counter++]);
	}
	free(str);
}

t_tkn	*ft_init_tkn(t_tkn *token)
{
	t_tkn	*ptr;

	if (token == NULL)
		return (NULL);
	ptr = ft_calloc(1, sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, token, sizeof(*ptr));
	return (ptr);
}

void	ft_destroy_tkn(void *ptr)
{
	t_tkn	*content;

	if (!ptr)
		return ;
	content = ptr;
	free(content->value);
	content->value = NULL;
	/*
	if (content->str[0])
		ft_sarrfree(&content->str);
	*/
	free(ptr);
}
