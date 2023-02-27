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
	NEWLINE,
	IO_NUMBER
}	t_tokens;

typedef	enum e_quotes
{
	INITIAL_STATE,
	DQUOTES,
	SQUOTES,
	BQUOTES
}t_quotes;

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
	LPAREN,
	RPAREN
}	t_operators;

typedef struct s_tkn
{
	char			*value;
	t_token			type;
	t_operators		operators;
	t_tokens		token_s;
	t_quotes		quotes;
	unsigned int	o_quotes;
	unsigned int	o_paren;
	unsigned int	o_brace;
}	t_tkn;

typedef struct s_lxr
{
	char	*str;
	size_t	pos;
}	t_lxr;

#endif
