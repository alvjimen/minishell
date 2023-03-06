/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:36:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/06 17:25:14 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LXR_H
# define LXR_H
# include <string.h>
# include <unistd.h>
# include <cmn.h>
# include <str.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef enum e_tokens
{
	WORD,
	ASSIGNMENT_WORD,
	NAME
}t_tokens;

typedef enum e_quotes
{
	I_STATE,
	DQUOTES,
	SQUOTES,
	BQUOTES,
	PAREN
}t_quotes;

typedef enum e_mode
{
	INTERACTIVE,
	NONINTERACTIVE
}t_mode;

typedef enum e_operators
{
	NONE,
	AND_IF,
	OR_IF
}	t_operators;

typedef struct s_tkn
{
	char			*value;
	t_operators		operators;
	t_tokens		token_s;
	t_quotes		quotes;
}	t_tkn;

typedef struct s_lxr
{
	char	*str;
	size_t	pos;
	t_tkn	tokens;
	size_t	num_tokens;
	t_mode	mode;
}	t_lxr;

t_lxr	*ft_init_lxr(char *s);
size_t	ft_run_ifs(t_lxr *lxr);
int		ft_char_quotes(char ch);
int		ft_char_end_string(char ch);
int		ft_char_ifs(char ch);
int		ft_token_varname(t_lxr	*lxr);
int		ft_token_quotes(t_lxr *lxr, size_t *counter);
void	ft_token_lower(t_lxr *lxr);
void	ft_token_greater(t_lxr *lxr);
void	ft_token_io_number(t_lxr *lxr);
int		ft_token_squotes(t_lxr *lxr, size_t *counter);
int		ft_token_dquotes(t_lxr *lxr, size_t *counter);
int		ft_token_bquotes(t_lxr *lxr, size_t *counter);
void	ft_token_rparen(t_lxr *lxr);
void	ft_token_lparen(t_lxr *lxr);
void	ft_token_end_string(t_lxr *lxr);
void	ft_token_new_line(t_lxr *lxr);
void	ft_token_pipe(t_lxr	*lxr);
void	ft_token_AND(t_lxr	*lxr);
void	ft_token_lbrace(t_lxr	*lxr);
void	ft_token_rbrace(t_lxr	*lxr);
void	ft_token_dollar(t_lxr	*lxr);
int		ft_get_more_input(t_lxr *lxr);
int		ft_token_quotes(t_lxr *lxr, size_t *counter);
void	ft_operators(t_lxr *lxr);

#endif
