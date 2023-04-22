/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordsplit_join_first_regex_star.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:42:00 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 09:42:22 by alvjimen         ###   ########.fr       */
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

char	**ft_wordsplit_join_first_regex_star(char **regex, char **old,
		char **words)
{
	regex = ft_sarradd(regex, *old);
	free(*old);
	*old = NULL;
	if (!regex)
		return (ft_wordsplit_join_first_regex_error(regex, words, 1));
	return (regex);
}
