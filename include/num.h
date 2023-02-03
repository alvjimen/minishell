/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:52:14 by alvjimen          #+#    #+#             */
/*   Updated: 2023/01/30 18:27:26 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_H
# define NUM_H

# include <unistd.h>
# include "str.h"

void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_base_unsigned(size_t nbr, char *base);
double	ft_atof(char	*str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
#endif
