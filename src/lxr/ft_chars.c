/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:12:57 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/02 18:40:57 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

int	ft_char_end_string(char ch)
{
	return (!ch);
}

int	ft_char_ifs(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}

int	ft_char_quotes(char ch)
{
	return (ch == '\'' || ch == '"');
}
