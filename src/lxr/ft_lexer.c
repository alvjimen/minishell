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

void	ft_token_bquotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '`')
	{
		printf("\` finded\n");
		lxr->pos ++;
	}
}

void	ft_token_squotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '\'')
	{
		printf("' finded\n");
		lxr->pos ++;
	}
}

void	ft_token_dquotes(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '"')
	{
		printf("\" finded\n");
		lxr->pos ++;
	}
}

void	ft_token_new_line(t_lxr *lxr)
{
	if (lxr->str[lxr->pos] == '\n')
	{
		printf("New line find\n");
		lxr->pos ++;
	}
}
