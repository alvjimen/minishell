/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_end_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:22:20 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/28 18:30:17 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_new_line(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '\n')
	{
		printf("New line find\n");
		lxr->pos++;
	}
}

void	ft_token_end_string(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '\0')
	{
		printf("Null EOS find\n");
		lxr->pos++;
	}
}
