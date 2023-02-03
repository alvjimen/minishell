/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:50:53 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 17:50:54 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCT_H
# define DCT_H

# include "mem.h"
# include "cmn.h"
# include "lst.h"

typedef struct s_dict
{
	void	*key;
	void	*value;
}	t_dict;

t_dict	*ft_dict_new(void *key, void *value);
void	*ft_dict_search(t_list *lst, void *key, size_t step_size);
void	ft_free_t_dict(void	*content);
#endif
