#include "lxr.h"

t_tkn	*init_tkn(char *s, int type, unsigned int paren, unsigned int brace)
{
	t_tkn	*tkn;
	
	tkn = ft_calloc(1, sizeof(t_tkn));
	tkn->value = s;
	tkn->type = type;
	tkn->paren = paren;
	tkn->brace = brace;
	return (tkn);
}
