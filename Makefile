NAME			=	push_swap
NAME_BONUS		=	my_checker
NAME_D			=	${NAME}_debug
NAME_BONUS_D	=	${NAME_BONUS}_debug		=	
LIB_NAME		=	libft.a
LIB_NAME_D		=	libft_debug.a
LIB_NAME_S		=	ft
LIB_PATH		=	lib/libft/
LIB				=	${LIB_PATH}${LIB_NAME}
LIB_D			=	${LIB_PATH}${LIB_NAME_D}
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FLAGS_D		=	-g
HEADER			=	includes/push_swap.h
HEADER_BONUS	=	includes/checker.h
HEADERS_SHARED	=	includes/shared.h includes/operations.h includes/vector.h includes/stack.h
SRCS			=	${shell find srcs/push_swap -name "*.c"}
SRCS_BONUS		=	${shell find srcs/checker -name "*.c"}
SRCS_SHARED		=	${shell find srcs/shared -name "*.c"}
OBJS			=	${SRCS:%.c=%.o}
OBJS_BONUS		=	${SRCS_BONUS:%.c=%.o}
OBJS_SHARED		=	${SRCS_SHARED:%.c=%.o}
OBJS_D			=	${SRCS:%.c=%_debug.o}
OBJS_BONUS_D	=	${SRCS_BONUS:%.c=%_debug.o}
OBJS_SHARED_D	=	${SRCS_SHARED:%.c=%_debug.o}
INCLUDES		=	-Iincludes
RM				=	rm -rf

%.o				:	%.c
					$(CC) ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_debug.o		:	%.c
					$(CC) ${CC_FLAGS_D} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

all				:	${NAME}

${NAME}			:	${LIB} ${HEADER} ${HEADERS_SHARED} $(OBJS) $(OBJS_SHARED)
					$(CC) $(INCLUDES) $(OBJS) $(OBJS_SHARED) -L${LIB_PATH} -l$(LIB_NAME_S) -o $(NAME)

debug			:	${NAME_D}

${NAME_D}		:	${LIB_D} ${HEADER} ${HEADERS_SHARED} $(OBJS_D) $(OBJS_SHARED_D)
					$(CC) $(INCLUDES) $(OBJS_D) $(OBJS_SHARED_D) -L${LIB_PATH} -l$(LIB_NAME_S) -o ${NAME_D}

bonus			:	${NAME_BONUS}

${NAME_BONUS}	:	${LIB} ${HEADER_BONUS} ${HEADERS_SHARED} $(OBJS_BONUS) $(OBJS_SHARED)
					$(CC) $(INCLUDES) $(OBJS_BONUS) $(OBJS_SHARED) -L${LIB_PATH} -l$(LIB_NAME_S) -o $(NAME_BONUS)

bonus_debug		:	${NAME_BONUS_D}

${NAME_BONUS_D}	:	${LIB_D} ${HEADER_BONUS} ${HEADERS_SHARED} $(OBJS_BONUS_D) $(OBJS_SHARED_D)
					$(CC) $(INCLUDES) $(OBJS_BONUS_D) $(OBJS_SHARED_D) -L${LIB_PATH} -l$(LIB_NAME_S) -o ${NAME_BONUS_D}

$(LIB_PATH)$(LIB_NAME)		:	
					@$(MAKE) -C $(LIB_PATH)

clean			:
					$(RM) ${OBJS} ${OBJS_BONUS} $(OBJS_SHARED) $(OBJS_D) $(OBJS_BONUS_D) $(OBJS_SHARED_D)
					@${MAKE} clean -C ${LIB_PATH}

fclean			:	clean 
					$(RM) $(NAME) ${NAME_D} ${NAME_BONUS} ${NAME_BONUS_D}
					@$(MAKE) fclean -C $(LIB_PATH)

re				:	fclean all

.PHONY			:	all debug bonus clean fclean re