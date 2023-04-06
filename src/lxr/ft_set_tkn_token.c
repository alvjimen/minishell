/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tkn_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:52:16 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/06 22:19:34 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_set_filename(void	*content)
{
	t_tkn	*token;

	token = (t_tkn *)content;
	if (!token)
		return ;
	token->token = FILENAME;
}

void	ft_set_hdfilename(void	*content)
{
	t_tkn	*token;

	token = (t_tkn *)content;
	if (!token)
		return ;
	token->token = HDFILENAME;
}

void	ft_set_error(void *content)
{
	t_tkn	*token;

	token = (t_tkn *)content;
	if (!token)
		return ;
	token->token = ERROR;
}
