
#***** Name *****#

NAME			=		minishell

#***** Sources / Objs *****#

SRC				=		main.c prompt.c utils.c init.c signal.c free.c utils2.c return_value.c exit.c utils_dollars.c\
						$(addprefix ./env/, env.c lst_chaine.c utils.c)\
						$(addprefix ./parsing/, parsing.c lst_parsing.c check_quote.c pipe.c l2_parsing.c lst_clear.c lst_utils.c)\
						$(addprefix ./error/, error_parsing.c)\
						$(addprefix ./bultins/, bultins.c bultins_env.c bultins_utils.c bultins_print.c bultin_echo.c bultin_cd.c bultin_pwd.c)\
						$(addprefix ./bultout/, bultout.c)\
						$(addprefix ./pipe/, pipe.c)\
						$(addprefix ./redirec/, redirection.c chevrons.c)

OBJS			=		$(SRC:.c=.o)

#***** Libft *****#

LIBFT			=		./libft/libft.a
MLIBFT			=		$(MAKE) -C libft

#***** Couleurs *****#

GREEN			=		\033[1;32m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m
BG_G			=		\033[42m

#***** Textes *****#

START			=		echo "$(GREEN)Start compilation\n$(ENDCOLOR)"
END_COMP		=		echo "$(GREEN)End compilation\n$(ENDCOLOR)"
S_OBJS			=		echo "$(RED)Suppression des objets\n$(ENDCOLOR)"
S_NAME			=		echo "$(RED)Suppression du programme\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_G)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

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
CFLAGS			=		-Wall -Wextra -Werror -g
L				=		$(CFLAGS) -g -fsanitize=address -fno-omit-frame-pointer
RM				=		rm -f
LIBS			= 		-I$(HOME)/.brew/Cellar/readline/8.2.1/include -lreadline \
						-L$(HOME)/.brew/Cellar/readline/8.2.1/lib
HEADER			=		-I./includes -I./libft/libft.h
ifeq ($(shell uname), Linux)

CC				=		gcc
LIBS			= 		-L/usr/local/lib -I/usr/local/include -lreadline
HEADER			=		-I./includes
endif

#***** Compilation *****#

all : lib start logo $(NAME)



lib:
			@$(MLIBFT) all
			@$(END_COMP_LIB)

start:
			@$(START)

logo :
			@$(MSHELL)


%.o:		%.c minishell.h ./libft/libft.h Makefile
			@$(CC) $(CFLAGS) -g $(HEADER) -c $< -o $@
			@$(CHARG_LINE)

$(NAME) :	${OBJS}
			@$(BS_N)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS} ${HEADER}
			@$(END_COMP)

l :			${OBJS}
			${MLIBFT} all
			${CC} ${L} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS} ${HEADER}
			@$(END_COMP)

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

docker:
	docker build -t arch .
	docker run -it --name archnm -v $(current_dir):/ft_nm arch

docker_start:
	docker start -i archnm

docker_run:
	docker exec -it archnm /bin/zsh

prune:
	docker system prune -a --volumes


.PHONY:		all clean fclean docker docker_start docker_run prune
