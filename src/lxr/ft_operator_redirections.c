/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator_redirections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:46:13 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/05 19:46:16 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

void	ft_token_io_number(t_lxr *lxr)
{
	if (ft_isdigit(lxr->str[lxr->pos]))
	{
		if (lxr->str[lxr->pos + 1] == '>')
		{
			lxr->pos++;
			ft_token_greater(lxr);
		}
		else if (lxr->str[lxr->pos + 1] == '<')
		{
			printf("io number find %d\n", lxr->str[lxr->pos]);
			lxr->pos++;
			ft_token_lower(lxr);
		}
		else
			lxr->pos ++;
	}
}

void	ft_token_greater(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '>')
	{
		if (lxr->str[lxr->pos + 1] == '>')
		{
			printf("DGreater find\n");
			lxr->pos++;
		}
		else
			printf("Greater find\n");
		lxr->pos ++;
	}
}
/* not valid delimiter for heredoc"()\n>;&"
void	ft_token_here_doc(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] != '<')
	{
		if (lxr->str[lxr->pos + 1] == '<')
		{
			printf("DLower find\n");
			lxr->pos++;

		}
		else
			printf("Lower find\n");
		lxr->pos++;
	}
	
}
*/

void	ft_token_lower(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '<')
	{
		if (lxr->str[lxr->pos + 1] == '<')
		{
			printf("DLower find\n");
			lxr->pos++;
		}
		else
			printf("Lower find\n");
		lxr->pos++;
	}
}
