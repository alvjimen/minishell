#include "lxr.h"
#include "str.h"
#include "cmn.h"


t_lxr	*init_lxr(char *s)
{
	t_lxr	*lxr;

	lxr = ft_calloc(1, sizeof(t_lxr));
	if (!lxr)
		return (NULL);
	lxr->str = s;
	return (lxr);
}

t_tkn	*ft_get_tkn_id(t_lxr *lexer)
{
	t_tkn	*tkn;
	int		type;
	size_t	pos;
	size_t	start_pos;
	char	*str;

	if (!lexer)
		return (NULL);
	type = TOKEN_ID;
	pos = lexer->pos;
	if (!lexer->str)
		return (NULL);
	while (lexer->str[pos] && ft_is_space(lexer->str[pos]))
		pos++;
	start_pos = pos;
	while (lexer->str[pos] && !ft_is_space(lexer->str[pos]))
		pos++;
	str = ft_substr(lexer->str, start_pos, pos - start_pos);
	if (!str)
		return (NULL);
	tkn = init_tkn(str, type, 0, 0);
	if (!tkn)
		return (NULL);
	lexer->pos = pos;
	return (tkn);
}

t_tkn	*ft_get_tkn_arg(t_lxr *lexer)
{
	t_tkn	*tkn;
	int		type;
	size_t	pos;
	size_t	start_pos;
	char	*str;

	if (!lexer)
		return (NULL);
	type = TOKEN_ARG;
	pos = lexer->pos;
	if (!lexer->str)
		return (NULL);
	while (lexer->str[pos] && ft_is_space(lexer->str[pos]))
		pos++;
	start_pos = pos;
	while (lexer->str[pos] && !ft_is_space(lexer->str[pos]))
		pos++;
	str = ft_substr(lexer->str, start_pos, pos - start_pos);
	if (!str)
		return (NULL);
	tkn = init_tkn(str, type, 0, 0);
	if (!tkn)
		return (NULL);
	lexer->pos = pos;
	return (tkn);
}

t_tkn	*ft_get_tkn_dquotes(t_lxr *lexer)
{
	t_tkn	*tkn;
	int		type;
	size_t	pos;
	size_t	start_pos;
	char	*str;

	if (!lexer)
		return (NULL);
	type = TOKEN_ARG;
	pos = lexer->pos;
	if (!lexer->str)
		return (NULL);
	while (lexer->str[pos] && ft_is_space(lexer->str[pos]))
		pos++;
	if (lexer->str[pos] == '"')
		pos++;
	start_pos = pos;
	while (lexer->str[pos] && lexer->str[pos] != '"')
		pos++;
	str = ft_substr(lexer->str, start_pos, pos - start_pos);
	/*if (!lexer->str[pos])
	*/
	/*the " doesn't end and i gonna ask for more character to get the string*/
	/*	tkn->dquote = 1;
	 I should still reading to find the next double quote"*/
	if (!str)
		return (NULL);
	tkn = init_tkn(str, type, 0, 0);
	if (!tkn)
		return (NULL);
	lexer->pos = pos;
	return (tkn);
}

t_tkn	*ft_get_token(t_lxr *lexer)
{
	t_tkn	*tkn;
	int		type;

	if (!lexer)
		return (NULL);
	if (!lexer->pos && *lexer->str != '(')
		tkn = ft_get_tkn_id(lexer);
	else
		tkn = ft_get_tkn_arg(lexer);
	if (!tkn)
		return (NULL);
	return (tkn);
}
