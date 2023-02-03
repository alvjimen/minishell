/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro </var/spool/mail/alvaro>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:16:30 by alvaro            #+#    #+#             */
/*   Updated: 2023/01/30 17:56:58 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRT_H
# define PRT_H
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define DEC "0123456789"
# define B_HASTAG 1
# define B_SPACE 2
# define B_PLUS 4
# define B_MINUS 8
# define B_ZERO 16
# define B_DOT 32

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "libft.h"

typedef struct s_flags
{
	unsigned int	flags: 6;
	unsigned int	width;
	unsigned int	accuracy;
	char			*str;
}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_str_uniq_char(char *str, int len);
int		ft_is_flag(char **str);
int		ft_flags_is_conversion(t_flags *flags, char *str);
int		ft_flags_is_digit(t_flags *flags, char *str);
int		ft_flags_is_str(char *str);
ssize_t	ft_putstr_pf(const char *str, t_flags *flags);
ssize_t	ft_putchar_pf(char c, t_flags *flags);
ssize_t	ft_accuracy(t_flags *flags);
ssize_t	ft_width(t_flags *flags);
ssize_t	ft_putpointer_pf(size_t pointer, t_flags *flags);
void	ft_putnbr_base_pf(long int nbr, char *base, ssize_t *count,
			t_flags *flags);
ssize_t	ft_putuint(unsigned int n, char *str, t_flags *flags);
void	ft_putnbr_base_unsigned_pf( size_t nbr, char *base, ssize_t *count);
void	ft_fill_flags(t_flags *flags, char **str);
void	ft_handle_flags(t_flags *flags, char **str);
int		ft_atoi_pf(char **str, t_flags *flags);
ssize_t	ft_strlen_pf(const char *str);
ssize_t	ft_numlen(int nbr, char *base, t_flags *flags);
ssize_t	ft_unumlen(size_t nbr, char *base);
void	ft_conversion(char **str, va_list args, ssize_t *count);
ssize_t	ft_conversion_len(t_flags *flags, void *data, char *str);
void	ft_fix_flags(t_flags *flags, char *str);
int		ft_fill_flags_zero(char **str, t_flags *flags);
void	ft_fix_flags_pointer(t_flags *flags, size_t pointer);
ssize_t	ft_putdigit(int nbr, t_flags *flags);
void	ft_fix_flags_digit(int nbr, t_flags *flags);
ssize_t	ft_putdigit(int nbr, t_flags *flags);
void	ft_fix_flags_unsigned(t_flags *flags, unsigned int uint);
ssize_t	ft_puthex_pf(unsigned int num, t_flags *flags, char *str);
void	ft_fix_flags_hex(t_flags *flags, size_t pointer, ssize_t len);
void	ft_free_t_flags(void *flags);
void	ft_free_struct(void *structs, void (*f) (void *));
void	*ft_memjoin(void const *s1, void const *s2, size_t l_s1, ssize_t l_s2);
void	*ft_memjoin_free_pf(void **nsbuf, void *line, size_t n_chr,
			ssize_t b_c);
size_t	ft_strlen_null(char *str);
void	ft_add_to_str_flags(t_flags *flags);
#endif
