#ifndef LXR_H
# define LXR_H
#include <string.h>
#include <cmn.h>
#include <readline/history.h>
#include <readline/readline.h>

typedef enum e_token
{
	TOKEN_ID,
	TOKEN_EQUALS,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_LT,
	TOKEN_GT,
	TOKEN_HEREDOC,
	TOKEN_HDELIM,
	TOKEN_HERESTRING,
	TOKEN_2GT,
	TOKEN_DQUOTES,
	TOKEN_SQUOTES,
	TOKEN_DOLLAR,
	TOKEN_BSLASH,
	TOKEN_ASTERISK,
	TOKEN_AMP,
	TOKEN_AND,
	TOKEN_PIPE,
	TOKEN_OR,
	TOKEN_SEMICOLONS,
	TOKEN_ARG
}	t_token;

typedef enum e_tokens
{
	WORD,
	ASSIGNMENT_WORD,
	NAME,
	NEWLINE
	IO_NUMBER
}	t_tokens;

typedef enum e_operators
{
	INITIAL_STATE,
	AND_IF,
	OR_IF,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESSGREAT,
	DLESSDASH,
	CLOBBER,
	LBRACE,
	RBRACE,
}	t_operators;
typedef struct s_tkn
{
	char			*value;
	t_token			type;
	unsigned int	paren;
	unsigned int	brace;
	unsigned int	quote: 1;
	unsigned int	dquote: 1;
	unsigned int	par: 1;
}	t_tkn;

typedef struct s_lxr
{
	char	*str;
	size_t	pos;
}	t_lxr;

t_tkn	*init_tkn(char *s, int type, unsigned int paren, unsigned int brace);
t_lxr	*init_lxr(char *s);
t_tkn	*ft_get_tkn_id(t_lxr *lexer);
t_tkn	*ft_get_tkn_arg(t_lxr *lexer);
t_tkn	*ft_get_token(t_lxr *lexer);
t_tkn	*ft_get_tkn_dquotes(t_lxr *lexer);
#endif
