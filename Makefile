# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 19:37:18 by alvjimen          #+#    #+#              #
#    Updated: 2023/04/22 15:55:22 by alvjimen         ###   ########.fr        #
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
LIB_NAME			:=	mini_shell.a
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
						ft_parenthesis_split\
						ft_syntax_analizer\
						ft_get_varname\
						ft_ls\
						ft_vars_expansion\
						ft_get_array_words\
						ft_unquote_quotes\
						ft_btree_builder\
						ft_set_tkn_token\
						ft_expand_vars_regex_unquote\
						ft_print_btree\
						ft_btree_destroy\
						ft_search_funcs\
						ft_vars_value\
						ft_dollar_expansion\
						ft_init_quotes\
						ft_join_\
						ft_join_quotes\
						ft_expand_inside_quotes\
						ft_expand_outside\
						ft_quotes_unquoting\
						ft_unquote_quotes_regex_expand_outside\
						ft_unquote_quotes_regex_utils\
						ft_regex_first\
						ft_regex_ls\
						ft_wordsplit_join\
						ft_wordsplit_join_first_regex_error\
						ft_wordsplit_join_checks_error\
						ft_regex_bash\
						ft_regex_quotes\
						ft_regex_quotes_loop\
						ft_isany_star\
						ft_search_funcs_v2\

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
						ft_sarrsort\
						ft_strncmp\
						ft_swap\
						ft_strchr\
						ft_bzero\
						ft_strjoinfree\
						ft_strbrk\
						ft_chrpos\
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
						ft_btree_swap\
						ft_btree_modify_root_conserve_branchs\

SRC-EXE				:=	main\
						ft_init\
						ft_get_path\
						ft_echo\
						ft_env\
						ft_signals\
						ft_exe_utils\
						ft_check_line\
						ft_conditions\
						ft_redirections\
						ft_isvar

DIR-SRC				:=	./src/
DIR-LXR				:=	lxr/
DIR-LIB_ADD			:=	lib_add/
DIR-TST				:=	test/
DIR-BTREE			:=	btree/
DIR-EXE				:=	exe/

SRC-LXR				:=	$(SRC-LXR:%=$(DIR-LXR)%)
SRC-LIB_ADD			:=	$(SRC-LIB_ADD:%=$(DIR-LIB_ADD)%)
SRC-BTREE			:=	$(SRC-BTREE:%=$(DIR-BTREE)%)
SRC-EXE				:=	$(SRC-EXE:%=$(DIR-EXE)%)
SRC-TST				:=	$(SRC-TST:%=$(DIR-TST)%)

SRC					:=	$(SRC-LXR) $(SRC-LIB_ADD) $(SRC-BTREE)

INC					:=	./include/
BUILD-DIR			:=	./.build/
CC					:=	clang
CFLAGS				:=	-Wall -Werror -Wextra -g3 -std=c89 #-pedantic\
						#-fsanitize=undefined -fsanitize=address #-O2
BUILD				:=	$(addprefix $(BUILD-DIR), $(addsuffix .o, $(SRC)))
BUILD-EXE			:=	$(addprefix $(BUILD-DIR), $(addsuffix .o, $(SRC-EXE)))
BUILD-TST			:=	$(addprefix $(BUILD-DIR), $(addsuffix .o, $(SRC-TST)))
DEPS				:=	$(BUILD:.o=.d)
PPFLAGS				:=	-MMD -MP -I $(INC) -I $(INCS)
#LDFLAGS			:=	-L $(LIBFT-DIR)
#LDLIBS				:=	-lft
END-RULE				=	@echo "$(CSI)$(BLINK)$(END)🎉🎊$(CSI)$(UNBLINK)$(END)\
	$(CSI)$(FOREGROUND)$(GREEN)$(END) $@ $(CSI)$(END)$(CSI)$(BLINK)$(END)🎊\
	$(CSI)$(UNBLINK)$(END)"

all:	$(NAME)

$(LIB_NAME):	$(BUILD)
	@ar -rcs $(LIB_NAME) $(BUILD)
	$(END-RULE)

$(NAME):	$(LIB_NAME) $(BUILD-EXE)
	@$(CC) $(CFLAGS) -lreadline -I $(INC) -o $(NAME) $(LIB_NAME) $(BUILD-EXE) src/libft.a
	$(END-RULE)


#@$(CC) -o $(NAME) $(CFLAGS) $(BUILD)#$(LDFLAGS) $(LDLIBS)

$(BUILD-DIR)%.o: $(DIR-SRC)%.c
	@$(DIR_DUP)
	@$(CC) $(PPFLAGS) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(BUILD-DIR)
	$(END-RULE)

fclean:	 clean
	@$(RM) $(NAME) test
	$(END-RULE)

re:	fclean	all
	$(END-RULE)


test:	$(NAME) $(BUILD-TST)
	@$(CC) $(CFLAGS) -o test -I $(INC) -lreadline $(BUILD-TST) $(NAME)
	$(END-RULE)


info-%:
	@$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	@$(info '$*'='$($*)')

tests: test
	@tests/tester.sh

.PHONY: all clean fclean re tester tests info-% print-% 
