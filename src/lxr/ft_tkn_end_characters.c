/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tkn_end_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:49:50 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 19:50:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_end_string(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '\0')
		printf("Newline token find\n");
}
