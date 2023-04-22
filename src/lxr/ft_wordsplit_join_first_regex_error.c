/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsplit_join_regex_error.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:45:21 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:45:28 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

char	**ft_wordsplit_join_first_regex_error(char **regex, char **words,
		int flag)
{
	if (flag > 1)
		ft_sarrfree(&regex);
	if (flag > 0)
		ft_sarrfree(&words);
	return (NULL);
}
