/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tkn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:09:12 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/16 17:37:04 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lxr.h"

/*
*TOKENS*
word name newline
*OPERATORS*
AND_IF		&&
OR_IF		||
DSEM		;;
DLESS		<<
DGREAT		>>
LESSAND		<&
GREATAND	>&
LESSGREAT	<>
DLESSDASH	<<-
CLOBBER		>|
*RESERVED WORDS*
If			if
Then		then
Else		else
Elif		elif
Fi			fi
Do			do
Done		done
Case		case
Esac		esac
While		while
Until		until
For			for
Lbrace		{
Rbrace		}
Bang		!
IN			in
*/

t_tkn	*ft_init_tkn(t_tkn *token)
{
	t_tkn	*ptr;

	if (token == NULL)
		return (NULL);
	ptr = ft_calloc(1, sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, token, sizeof(*ptr));
	return (ptr);
}

void	ft_destroy_tkn(void *ptr)
{
	t_tkn *content;
	if (!ptr)
		return ;
	content = ptr;
	free(content->value);
	ft_lstclear(&content->related, ft_destroy_tkn);
	free(ptr);
}
