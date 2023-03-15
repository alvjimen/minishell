/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:52:29 by alvjimen          #+#    #+#             */
/*   Updated: 2022/06/27 16:52:39 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_num;

	if (!(size_t)lst)
		return (0);
	lst_num = 1;
	while (lst->next)
	{
		lst_num++;
		lst = lst->next;
	}
	return (lst_num);
}
