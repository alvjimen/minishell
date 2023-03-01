/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:00:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/01 20:35:33 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"
/*
TODO return value Status
	1		Empty value.
	O		ALL OK.
	-1		Ignored TOKEN.
	-255	Unexpeted Value.
*/

static int	ft_valid_char(char ch)
{
	return (ch && ch != '\n' && ch != ' ');
}

int	ft_valid_name(t_lxr *lxr, size_t *counter)
{
	lxr->tokens.token_s = NAME;
	printf("Token %s:\n", "VALUE OF VAR");
	write(1, &lxr->str[lxr->pos], ++counter[0]);
	write(1, "\n", 1);
	lxr->pos += *counter;
	return (0);
}

int	ft_empty_name(t_lxr *lxr, size_t counter)
{
	printf("Token %s:\n", "Empty Value of var");
	lxr->pos += counter;
	return (1);
}

int	ft_ignored_name(t_lxr *lxr, size_t counter)
{
	printf("Token %s:\n", "Ignored token");
	lxr->pos += counter;
	return (-1);
}

static int	ft_token_name_first_char_valid(t_lxr *lxr, size_t counter)
{
	while (ft_valid_char(lxr->str[lxr->pos + counter]))
		counter++;
	if (lxr->str[lxr->pos + counter] == '\n'
		|| !lxr->str[lxr->pos + counter])
		return (ft_valid_name(lxr, &counter));
	else if (lxr->str[lxr->pos + counter] == ' ')
	{
		while (lxr->str[lxr->pos + counter] == ' ')
			counter++;
		if (lxr->str[lxr->pos + counter] == '\n'
			|| !lxr->str[lxr->pos + counter])
			return (ft_valid_name(lxr, &counter));
		else
			return (ft_ignored_name(lxr, counter));
	}
	else
	{
		printf("Unexpected value\n");
		return (-255);
	}
}

int	ft_token_name(t_lxr	*lxr)
{
	size_t	counter;

	counter = 0;
	if (ft_valid_char(lxr->str[lxr->pos]))
		return (ft_token_name_first_char_valid(lxr, counter));
	else if (lxr->str[lxr->pos] == '\n' || !lxr->str[lxr->pos])
		return (ft_empty_name(lxr, counter));
	else if (lxr->str[lxr->pos] == ' ')
	{
		while (lxr->str[lxr->pos + counter] == ' ')
			counter++;
		if (lxr->str[lxr->pos + counter] == '\n'
			|| lxr->str[lxr->pos + counter] == '\0')
			return (ft_empty_name(lxr, counter));
		else
			return (ft_ignored_name(lxr, counter));
		return (-255);
	}
	return (-255);
}
