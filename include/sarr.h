#ifndef SARR_H
# define SARR_H
# include <stdlib.h>

char	**ft_sarrcpy(char **arr);
int		ft_sarrsize(char **arr);
char	**ft_sarradd(char **arr, char *string);
void    ft_sarrfree(char ***arr);
char	**ft_sarrrmi(int index, char **arr);
int		ft_sarrprint(char **arr);
int		ft_sarrcmp(char **arr, char *str);
char    **ft_sarrrep(char **arr, int index, char *str);
#endif
