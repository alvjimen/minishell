/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:00:42 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/21 20:23:41 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lxr.h"

/**/
char	*ft_var_value(char **sarr, char *var_name)
{
	sarr = NULL;
	var_name = NULL;
	if (!sarr || !var_name)
		return (ft_strdup("var value"));
	return (ft_strdup("var value"));
}
/**/
/**a/
char	*ft_var_value(char **sarr, char *var_name)
{
	sarr = NULL;
	var_name = NULL;
	return (ft_strdup(""));
}
/a**/
