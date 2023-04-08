/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sarr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:15:54 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/08 15:29:35 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SARR_H
# define SARR_H
# include <stdlib.h>

char	**ft_sarrcpy(char **arr);
int		ft_sarrsize(char **arr);
char	**ft_sarradd(char **arr, char *string);
void	ft_sarrfree(char ***arr);
char	**ft_sarrrmi(int index, char **arr);
int		ft_sarrprint(char **arr);
int		ft_sarrcmp(char **arr, char *str);
char	**ft_sarrrep(char **arr, int index, char *str);
void	ft_sarrsort(char **sarr);
char	**ft_sarrmerge(char **arr, char **arr_merge, int index);
#endif
