# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 20:37:09 by piow00            #+#    #+#              #
#    Updated: 2022/09/07 14:10:01 by aboymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** Name *****#

NAME			=		minishell

#***** Sources / Objs *****#

SRC				=		main.c prompt.c
OBJS			=		$(SRC:.c=.o)

#***** Libft *****#

LIBFT			=		libft/libft.a
MLIBFT			=		$(MAKE) -C libft

#***** Couleurs *****#
GREEN			=		\033[1;32m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m

#***** Textes *****#

START			=		echo "$(GREEN)Start compilation\n$(ENDCOLOR)"
END_COMP		=		echo "$(GREEN)End compilation\n$(ENDCOLOR)"
S_OBJS			=		echo "$(RED)Suppression des objets\n$(ENDCOLOR)"
S_NAME			=		echo "$(RED)Suppression du programme\n$(ENDCOLOR)"

#***** Logo *****#

MSHELL			=		echo "$(GREEN) \t++\      ++\ ++\           ++\           ++\                 ++\ ++\ \n\
									 \t+++\    +++ |\__|          \__|          ++ |                ++ |++ |\n\
									 \t++++\  ++++ |++\ +++++++\  ++\  +++++++\ +++++++\   ++++++\  ++ |++ |\n\
									 \t++\++\++ ++ |++ |++  __++\ ++ |++  _____|++  __++\ ++  __++\ ++ |++ |\n\
									 \t++ \+++  ++ |++ |++ |  ++ |++ |\++++++\  ++ |  ++ |++++++++ |++ |++ |\n\
									 \t++ |\+  /++ |++ |++ |  ++ |++ | \____++\ ++ |  ++ |++   ____|++ |++ |\n\
									 \t++ | \_/ ++ |++ |++ |  ++ |++ |+++++++  |++ |  ++ |\+++++++\ ++ |++ |\n\
									 \t\__|     \__|\__|\__|  \__|\__|\_______/ \__|  \__| \_______|\__|\__|$(ENDCOLOR)\n"

#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror
L				=		$(CFLAGS) -g -fsanitize=address -fno-omit-frame-pointer
RM				=		rm -f
LIBS			= 		-I$(HOME)/.brew/Cellar/readline/8.1.2/include
HEADER			=		-I./includes -lreadline #-lhistory
# LIBS			= 		-L./readline/lib/ -lreadline -lhistory

ifeq ($(shell uname), Linux)

CC				=		gcc
LIBS			= 		-L/home/linuxbrew/.linuxbrew/lib/ -lreadline -lhistory
endif

#***** Compilation *****#

all : $(NAME)

$(NAME) : logo start minishell

logo :
			@$(MSHELL)

start : 
			@$(START)

minishell:	${OBJS}
			${MLIBFT} all
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS} ${HEADER}
			@$(END_COMP)

l :			${OBJS}
			${MLIBFT} all
			${CC} ${L} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS} ${HEADER}

#***** Clean *****#

clean:
			@$(S_OBJS)
			${RM} ${OBJS}
			${MLIBFT} clean

fclean:		clean
			@$(S_NAME)
			${RM} ${NAME}
			${MLIBFT} fclean

re:			fclean all

.PHONY:		all bonus clean fclean re



                                                                     
