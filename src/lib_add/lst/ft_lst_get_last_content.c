/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_last_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:51:46 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:17:43 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lst.h"

void	*ft_get_last_content(t_list *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node->content);
}
