/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:36:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/03/15 19:49:08 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LXR_H
# define LXR_H
# define NOT_TOKEN 255
# include <string.h>
# include <unistd.h>
# include <libft.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef enum e_tokens
{
	WORD,
	ASSIGNMENT_WORD,
	PARENTHESIS
}	t_tokens;

typedef enum e_states
{
	I_STATE,
	DQUOTES,
	SQUOTES,
	PAREN
}	t_states;

typedef enum e_mode
{
	INTERACTIVE,
	NONINTERACTIVE
}	t_mode;

typedef enum e_operators
{
	NONE,
	AND_IF,
	OR_IF,
	PIPE,
	GREATER,
	DGREATER,
	LOWER,
	DLOWER
}	t_operators;

typedef struct s_tkn
{
	char			*value;
	t_operators		operators;
	t_tokens		token;
	t_states		states;
	t_list			*related;
}	t_tkn;

typedef struct s_lxr
{
	char	*str;
	size_t	pos;
	t_tkn	tokens;
	size_t	num_tokens;
	t_mode	mode;
	t_list	*lst;
}	t_lxr;

t_lxr	*ft_init_lxr(char *s);
size_t	ft_run_ifs(t_lxr *lxr);
int		ft_char_states(char ch);
int		ft_char_end_string(char ch);
int		ft_char_ifs(char ch);
int		ft_token_varname(t_lxr	*lxr);
int		ft_token_value(t_lxr *lxr, size_t *counter);
int		ft_token_states(t_lxr *lxr, size_t *counter);
int		ft_token_lower(t_lxr *lxr);
int		ft_token_greater(t_lxr *lxr);
void	ft_token_io_number(t_lxr *lxr);
int		ft_squotes(t_lxr *lxr, size_t *counter);
int		ft_dquotes(t_lxr *lxr, size_t *counter);
void	ft_token_new_line(t_lxr *lxr);
int		ft_token_pipe(t_lxr	*lxr);
int		ft_token_AND(t_lxr	*lxr);
int		ft_get_more_input(t_lxr *lxr);
int		ft_quotes(t_lxr *lxr, size_t *counter);
int		ft_operators(t_lxr *lxr);
int		ft_char_operator(t_lxr *lxr, size_t *counter);
int		ft_get_tokens(t_lxr *lxr);
int		ft_parenthesis(t_lxr *lxr);
int		ft_token_redirect_io(t_lxr *lxr);
int		ft_tkn_pipeline(t_lxr *lxr);
t_tkn	*ft_init_tkn(t_tkn *token);
void	ft_print_lst(void	*ptr);

#endif
