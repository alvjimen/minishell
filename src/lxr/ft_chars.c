/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:12:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/06 16:48:46 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_char_end_string(char ch)
{
	return (ch == '\0');
}

int	ft_char_ifs(char ch)
{
	return (ch == ' ' || ch == '\t');
}

int	ft_char_quotes(char ch)
{
	return (ch && (ch == '\'' || ch == '"' || ch == '`'));
}
