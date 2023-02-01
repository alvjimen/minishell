/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:02:32 by alvjimen          #+#    #+#             */
/*   Updated: 2023/02/01 18:10:53 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "tokenizer.h"

void	ft_tokenizer(char *str)
{
	
	size_t	pos;

	pos = 0;
	if (!str)
		return ;
	while (str[pos])
	{
		if (str[pos] == '\'')
			write(1, "single q\n", 9);
		else if (str[pos] == '"')
			write(1, "double q\n", 9);
		else if (str[pos] == '(')
			write(1, "open par\n", 9);
		else if (str[pos] == ')')
			write(1, "close par\n", 10);
		else if (str[pos] == '|' && str[pos + 1] == '|')
		{
			write(1, "OR\n", 3);
			pos++;
		}
		else if (str[pos] == '&' && str[pos + 1] == '&')
		{
			write(1, "AND\n", 4);
			pos++;
		}
		else if (str[pos] == '|')
			write(1, "PIPE\n", 5);
		else if (str[pos] == '&')
			write(1, "BG\n", 3);
		else if (str[pos] == '>' && str[pos + 1] == '>')
		{
			write(1, "2GT\n", 4);
			pos++;
		}
		else if (str[pos] == '>')
			write(1, "GT\n", 3);
		else if (str[pos] == '<' && str[pos + 1] == '<')
		{
			write(1, "2LT\n", 4);
			pos ++;
		}
		else if (str[pos] == '<')
			write(1, "LT\n", 3);
		pos ++;
	}
}
