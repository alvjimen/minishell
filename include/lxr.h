/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:36:15 by alvjimen          #+#    #+#             */
/*   Updated: 2023/04/22 15:48:36 by alvjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LXR_H
# define LXR_H
# define NOT_TOKEN 255
# define FAILURE 1
# define SUCCESS 0
# define VAR 0

# include <string.h>
# include <unistd.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <errno.h>
# include "libft.h"
# include "btree.h"
# include "sarr.h"

typedef enum e_tokens
{
	NO_TOKEN,
	WORD,
	ASSIGNMENT_WORD,
	FILENAME,
	HDFILENAME,
	PARENTHESIS,
	OPERATOR,
	ERROR,
	SYNTAX_ERROR,
	AMBIGUOUS
}	t_tokens;

typedef enum e_states
{
	I_STATE,
	DQUOTES,
	SQUOTES,
	PAREN,
	DOLLAR
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
	char			**str;
	char			**regex;
	t_operators		operators;
	t_tokens		token;
	size_t			num_tokens;
	unsigned int	found: 1;
	t_states		states;
}	t_tkn;

typedef struct s_quotes
{
	char	**prev_quotes;
	char	**inner_quotes;
	char	*last_unquote;
	size_t	counter;
}	t_quotes;

typedef struct s_lxr
{
	size_t	pos;
	char	*str;
	t_tkn	tokens;
	size_t	num_tokens;
	t_mode	mode;
	t_btree	*btree;
	int		errors;
	size_t	counter;
}	t_lxr;

typedef struct s_vars
{
	char	*name;
	char	*value;
	char	*tmp;
}	t_vars;

t_lxr		*ft_init_lxr(char *s);
size_t		ft_run_ifs(t_lxr *lxr);
int			ft_char_states(char ch);
int			ft_char_end_string(char ch);
int			ft_char_ifs(char ch);
int			ft_token_varname(t_lxr	*lxr);
int			ft_token_value(t_lxr *lxr, size_t *counter);
int			ft_token_states(t_lxr *lxr, size_t *counter);
int			ft_token_lower(t_lxr *lxr);
int			ft_token_greater(t_lxr *lxr);
void		ft_token_io_number(t_lxr *lxr);
int			ft_squotes(t_lxr *lxr, size_t *counter);
int			ft_dquotes(t_lxr *lxr, size_t *counter);
void		ft_token_new_line(t_lxr *lxr);
int			ft_token_pipe(t_lxr	*lxr);
int			ft_token_AND(t_lxr	*lxr);
int			ft_get_more_input(t_lxr *lxr);
int			ft_quotes(t_lxr *lxr, size_t *counter);
int			ft_operators(t_lxr *lxr);
int			ft_char_operator(t_lxr *lxr, size_t *counter);
int			ft_get_tokens(t_lxr *lxr);
int			ft_parenthesis(t_lxr *lxr);
int			ft_token_redirect_io(t_lxr *lxr);
int			ft_tkn_pipeline(t_lxr *lxr);
t_tkn		*ft_init_tkn(t_tkn *token);
void		ft_print_lst(void	*ptr);
void		*ft_add_string_to_list(t_lxr *lxr, size_t counter);
void		ft_destroy_tkn(void *ptr);
t_list		*ft_split_list(t_list **lst, int (*f)(void *));
int			ft_operators_split(t_btree **root);
t_list		*ft_search_list(t_list *lst, int (*f)(void *));
int			ft_operators_interpipelines(void *ptr);
int			ft_operators_intercmd(void *ptr);
int			ft_operators_intracmd(void *ptr);
int			ft_tokens_word(void *ptr);
char		*ft_get_varname(t_lxr *lxr);
char		*ft_vars_expansion(char *str);
int			ft_tokens_assignment_word(void *ptr);
char		**ft_get_array_words(t_btree **root);
char		**ft_ls(char *str);
void		ft_btree_apply_to_node_pointer_infix(t_btree **root,
				void (*applyf)(void **));
void		ft_operators_split_recursively(void **ptr);
int			ft_syntax_analizer(t_btree *root, t_lxr *lxr);
void		ft_unquote_quotes_recursively(void **ptr);
void		ft_unquote_quotes(t_btree **root);
t_btree		*ft_btree_builder(char	*str);
void		ft_parenthesis_expansion_recursively(void **ptr);
void		ft_get_array_words_recursively(void **ptr);
void		ft_set_hdfilename(void	*content);
void		ft_set_filename(void	*content);
void		ft_set_error(void *content);
void		ft_set_ambiguous(void *content);
char		**ft_regex_quotes(t_quotes *quotes);
t_quotes	*ft_init_quotes(t_lxr *lxr);
t_quotes	*ft_destroy_quotes(t_quotes **quotes);
int			ft_regex_bash(char ***regex, char *matched, char *str);
void		*ft_join_quotes(t_quotes *quotes);
void		ft_unquote_quotes_regex_recursively(void **ptr);
char		**ft_regex_ls(t_quotes *quotes, char *str);
void		ft_expand_vars_regex_unquote(t_btree **root);
void		ft_print_btree(t_btree *root);
void		ft_btree_destroy(t_btree **root);
char		*ft_var_value(char **sarr, char *var_name);
char		*ft_dollar_expansion(t_lxr **lxr, t_vars *vars);
t_quotes	*ft_destroy_quotes(t_quotes **quotes);
t_quotes	*ft_init_quotes(t_lxr *lxr);
void		ft_join_(char *old, char *str, char **join);
void		*ft_join_quotes(t_quotes *quotes);
void		*ft_expand_inside_quotes(t_quotes *quotes);
void		*ft_expand_outside(t_quotes *quotes);
int			ft_quotes_unquoting(t_quotes *quotes);
char		*ft_unquote_quotes_regex_expand_outside(t_lxr **lxr,
				t_tkn *content);
void		*ft_unquote_quotes_regex_new_root(t_lxr **lxr, t_btree **root);
void		ft_unquote_quotes_regex_set_filename(t_lxr *lxr, t_tkn *content);
void		*ft_unquote_quotes_regex_new_tkns(t_lxr *lxr, t_tkn *content,
				char *str);
char		*ft_start_notstar(char **matched, char *str, size_t *counter);
int			ft_just_asterisk(char *regex);
char		**ft_regex_ls(t_quotes *quotes, char *str);
char		**ft_wordsplit_join(char **old, char *str, char **regex);
char		**ft_wordsplit_join_first_regex_error(char **regex, char **words,
				int flag);
char		**ft_wordsplit_join_checks_error(char **regex, char **old);
int			ft_regex_bash(char ***regex, char *matched, char *str);
char		**ft_regex_quotes(t_quotes *quote);
char		**ft_regex_quotes_loop(t_quotes *quote, char ***regex, char **old,
				size_t *counter);
int			ft_isany_star(t_quotes *quotes);
int			ft_tokens_get_array_words(void *ptr);
#endif
