/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsplit_join_first_regex_star.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:42:00 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/26 10:34:26 by alvjimen         ###   ########.fr       */
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
