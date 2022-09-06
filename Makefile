# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 20:37:09 by piow00            #+#    #+#              #
#    Updated: 2022/09/07 01:29:24 by piow00           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** Name *****#

NAME			=		minishell

#***** Sources / Objs *****#

SRC				=		main.c
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
HEADS			= 		-I. -I${LIBFT} -I./readline/include/
LIBS			= 		-L./readline/lib/ -lreadline -lhistory

ifeq ($(shell uname), Linux)

CC				=		gcc
HEADS			= 		-I. -I${LIBFT} -I/home/linuxbrew/.linuxbrew/include/
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
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS}
			@$(END_COMP)

l :			${OBJS}
			${MLIBFT} all
			${CC} ${L} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS}

#***** Clean *****#

clean:
			@$(S_OBJS)
			${RM} ${OBJS}
			${MAKELIB} clean

fclean:		clean
			@$(S_NAME)
			${RM} ${NAME}
			${MAKELIB} fclean

re:			fclean all

.PHONY:		all bonus clean fclean re



                                                                     
