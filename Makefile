# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 19:37:18 by alvjimen          #+#    #+#              #
#    Updated: 2023/03/23 17:51:23 by alvjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS			+=	--no-print-directory
CSI					:=	\033[
SEPARATOR			:=	;
FOREGROUND			:=	3
BACKGROUND			:=	4
BLINK				:=	5
UNBLINK				:=	25
FOREGROUND_BRIGHT	:=	9
BACKGROUND_BRIGHT	:=	10
FORE/BACKGROUND_SET	:=	8
						#red_number 0-255;green_number 0-255; blue_number 0-255;
RGB					:=	;2;#255;0;0
3-4BITS				:=	:5:#
BLACK				:=	0
RED					:=	1
GREEN				:=	2
YELLOW				:=	3
BLUE				:=	4
MAGENTA				:=	5
LIGHT_BLUE			:=	6
END					:=	m

# UTENSILS
SHELL				:=	/bin/sh
NAME				:=	mini_shell
RM					:=	rm -rf
# @D take the part of the directory
DIR_DUP				=	mkdir -p $(@D)

# INGREDIENTS
SRC-LXR				:=	ft_lexer\
						ft_init_tkn\
						ft_tkn_var_name\
						ft_tkn_var_value\
						ft_quotes\
						ft_run_ifs\
						ft_operator_redirections\
						ft_chars\
						ft_get_more_input\
						ft_dquotes\
						ft_squotes\
						ft_tkn_word\
						ft_char_operator\
						ft_operators\
						ft_operator_pipe_and_or\
						ft_operator_redirections\
						ft_get_tokens\
						ft_parenthesis\
						ft_add_string_to_list\
						ft_split_list\
						ft_search_list\
						ft_operators_split\
						ft_syntax_analizer\
						ft_get_varname\

SRC-LST				:=	ft_lstnew_bonus\
						ft_lstadd_front_bonus\
						ft_lstsize_bonus\
						ft_lstlast_bonus\
						ft_lstadd_back_bonus\
						ft_lstdelone_bonus\
						ft_lstclear_bonus\
						ft_lstiter_bonus\
						ft_lstmap_bonus\
						ft_lstnodeiteri\
						ft_lst_get_last_content\

DIR-LST				:=	lst/
SRC-LST				:=	$(SRC-LST:%=$(DIR-LST)%)

SRC-LIB_ADD			:=	ft_split\
						ft_strnstr\
						ft_calloc\
						ft_strdup\
						ft_strlen\
						ft_substr\
						ft_memcpy\
						ft_split_chars\
						ft_is_space\
						ft_isdigit\
						ft_isalpha\
						ft_isalnum\
						ft_substr\
						ft_strlen\
						ft_strdup\
						ft_memcpy\
						ft_strjoin\
						ft_memmove\
						ft_putstr_fd\
						ft_sarradd\
						ft_sarrcmp\
						ft_sarrcpy\
						ft_sarrfree\
						ft_sarrprint\
						ft_sarrrep\
						ft_sarrrmi\
						ft_sarrsize\
						$(SRC-LST)
						
SRC-TST				:=	test

SRC-BTREE			:=	ft_btree_apply_by_level\
						ft_btree_apply_infix\
						ft_btree_apply_suffix\
						ft_btree_apply_prefix\
						ft_btree_insert_data\
						ft_btree_new_node\
						ft_btree_level_count\
						ft_btree_add_left\
						ft_btree_add_right\
						ft_btree_add_parent\
						ft_btree_clear\
						ft_btree_delone\

DIR-SRC				:=	./src/
DIR-LXR				:=	lxr/
DIR-LIB_ADD			:=	lib_add/
DIR-TST				:=	test/
DIR-BTREE			:=	btree/

SRC-LXR				:=	$(SRC-LXR:%=$(DIR-LXR)%)
SRC-LIB_ADD			:=	$(SRC-LIB_ADD:%=$(DIR-LIB_ADD)%)
SRC-TST				:=	$(SRC-TST:%=$(DIR-TST)%)
SRC-BTREE			:=	$(SRC-BTREE:%=$(DIR-BTREE)%)

SRC					:=	$(SRC-LXR) $(SRC-LIB_ADD) $(SRC-BTREE)

INC					:=	./include/
BUILD-DIR			:=	./.build/
CC					:=	clang
CFLAGS				:=	-Wall -Werror -Wextra -g3 -std=c89 #-pedantic -fsanitize=undefined -fsanitize=address #-O2
BUILD				:=	$(addprefix $(BUILD-DIR), $(addsuffix .o, $(SRC)))
BUILD-TST			:=	$(addprefix $(BUILD-DIR), $(addsuffix .o, $(SRC-TST)))
DEPS				:=	$(BUILD:.o=.d)
PPFLAGS				:=	-MMD -MP -I $(INC) -I $(INCS)
#LDFLAGS			:=	-L $(LIBFT-DIR)
#LDLIBS				:=	-lft
END-RULE				=	@echo "$(CSI)$(BLINK)$(END)🎉🎊$(CSI)$(UNBLINK)$(END)\
	$(CSI)$(FOREGROUND)$(GREEN)$(END) $@ $(CSI)$(END)$(CSI)$(BLINK)$(END)🎊\
	$(CSI)$(UNBLINK)$(END)"

all:	$(NAME)

$(NAME):	$(BUILD)
	@ar -rcs $(NAME) $(BUILD)
	$(END-RULE)

#@$(CC) -o $(NAME) $(CFLAGS) $(BUILD)#$(LDFLAGS) $(LDLIBS)

$(BUILD-DIR)%.o: $(DIR-SRC)%.c
	@$(DIR_DUP)
	@$(CC) $(PPFLAGS) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(BUILD-DIR)

fclean:	 clean
	@$(RM) $(NAME)

re:	fclean	all


test:	$(NAME) $(BUILD-TST)
	@$(CC) $(CFLAGS) -o test -I $(INC) -lreadline $(BUILD-TST) $(NAME)
#@$(MAKE) fclean

info-%:
	@$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	@$(info '$*'='$($*)')

TEST-DIR	=	tests
tester: test
	@tests/tester.sh

.PHONY: all clean fclean re testers info-% print-% 
