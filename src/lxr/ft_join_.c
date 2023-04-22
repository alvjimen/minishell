/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:41:39 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 08:43:40 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_join_(char *old, char *str, char **join)
{
	if (!old)
		*join = ft_strjoin("", str);
	else
		*join = ft_strjoin(old, str);
}

