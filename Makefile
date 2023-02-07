# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvjimen <alvjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 19:37:18 by alvjimen          #+#    #+#              #
#    Updated: 2023/02/07 20:00:00 by alvjimen         ###   ########.fr        #
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

SRC-LIB_ADD			:=	ft_split\
						ft_strnstr\
						ft_calloc\
						ft_strdup\
						ft_strlen\
						ft_substr\
						ft_memcpy\
						ft_split_chars\
						ft_is_space\

DIR-SRC				:=	./src/
DIR-LXR				:=	lxr/
DIR-LIB_ADD			:=	lib_add/
DIR-TST				:=	test/

SRC-LXR				:=	$(SRC-LXR:%=$(DIR-LXR)%)
SRC-LIB_ADD			:=	$(SRC-LIB_ADD:%=$(DIR-LIB_ADD)%)

SRC					:=	$(SRC-LXR) $(SRC-LIB_ADD)

INC					:=	./include/
BUILD-DIR			:=	./.build/
CC					:=	clang
CFLAGS				:=	-Wall -Werror -Wextra -g3 -std=c89 -pedantic -fsanitize=undefined -fsanitize=address #-O2
BUILD				:=	$(addprefix $(BUILD-DIR), $(addsuffix .o, $(SRC)))
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

fclean:	
	@$(RM) $(BUILD-DIR) $(NAME)

re:	fclean	all


test:	$(NAME)
	$(CC) $(CFLAGS) -o test -I $(INC) -lreadline src/test/test.c $(NAME) 

info-%:
	@$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	@$(info '$*'='$($*)')

.PHONY: all clean fclean re info-% print-%