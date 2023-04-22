/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsplit_join_checks_error.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:55:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:55:55 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	**ft_wordsplit_join_checks_error(char **regex, char **old)
{
	ft_sarrfree(&regex);
	free(*old);
	return (NULL);
}
