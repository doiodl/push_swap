# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btheia <btheia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 21:07:00 by flogan            #+#    #+#              #
#    Updated: 2019/11/18 19:37:35 by btheia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(PUSH_SWAP) $(CHECKER)
LIBFT_A =		libftprintf.a

COMP =			gcc -Wall -Werror -Wextra -I include -I libft/include -c -o

OBJ_DIR =		obj/
S_SRC_DIR =		shared/
P_SRC_DIR =		push_swap_dir/
C_SRC_DIR =		checker_dir/
LIBFT =			libft/

S_SRC =			algorithm.c \
				new_alg.c \
				erro.c \
				new2alg.c \
				cheacek_1.c \
				gnl.c \
				list_func.c \
				list_func2.c \
				list_num.c \

P_SRC =			push_main.c \

C_SRC =			checker_main.c \

S_OBJ =			$(S_SRC:%.c=%.o)
P_OBJ =			$(P_SRC:%.c=%.o)
C_OBJ =			$(C_SRC:%.c=%.o)

OBJ =			$(S_OBJ) $(P_OBJ) $(C_OBJ)

S_SRC_PATH =   	$(S_SRC:%=$(S_SRC_DIR)%)
P_SRC_PATH =   	$(P_SRC:%=$(P_SRC_DIR)%)
C_SRC_PATH =   	$(C_SRC:%=$(C_SRC_DIR)%)
SRC_PATH =		$(S_SRC_PATH) $(P_SRC_PATH) $(C_SRC_PATH)

S_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(S_OBJ))
P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
C_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(C_OBJ))
OBJ_PATH =		$(S_OBJ_PATH) $(P_OBJ_PATH) $(C_OBJ_PATH)

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n"DONE"\\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(S_OBJ_PATH) $(P_OBJ_PATH) *.a -o push_swap \
					-I include -I libft/include
				@gcc $(S_OBJ_PATH) $(C_OBJ_PATH) *.a -o checker \
					-I include -I libft/include

$(S_OBJ_PATH):	$(S_SRC_PATH)
				@$(MAKE) $(S_OBJ)

$(P_OBJ_PATH):	$(P_SRC_PATH)
				@$(MAKE) $(P_OBJ)

$(C_OBJ_PATH):	$(C_SRC_PATH)
				@$(MAKE) $(C_OBJ)

$(S_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(S_SRC_DIR)$(@:%.o=%.c)
$(C_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(C_SRC_DIR)$(@:%.o=%.c)
$(P_OBJ):		$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(P_SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

color:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo Cleaned libft object files

fclean:			clean
				@/bin/rm -f $(PUSH_SWAP) $(CHECKER) $(FT_PRINTF_A) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo Cleaned $(NAME)

re: 			fclean all

.PHONY:			all clean flcean re color
