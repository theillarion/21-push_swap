NAME			=	push_swap
NAME_D			=	${NAME}_debug
LIB_NAME		=	libft.a
LIB_NAME_D		=	libft_debug.a
LIB_NAME_S		=	ft
LIB_PATH		=	lib/libft/
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FLAGS_D		=	-g
SRC_MAIN		=	srcs/main.c
SRCS_STACK		=	${shell find srcs/stack -name "*.c"}
SRCS_VECTOR		=	${shell find srcs/vector -name "*.c"}
SRCS_OPERS		=	${shell find srcs/operations -name "*.c"}
OBJ_MAIN		=	${SRC_MAIN:%.c=%.o}
OBJS_STACK		=	${SRCS_STACK:%.c=%.o}
OBJS_VECTOR		=	${SRCS_VECTOR:%.c=%.o}
OBJS_OPERS		=	${SRCS_OPERS:%.c=%.o}
OBJ_MAIN_D		=	${SRC_MAIN:%.c=%_debug.o}
OBJS_STACK_D	=	${SRCS_STACK:%.c=%_debug.o}
OBJS_VECTOR_D	=	${SRCS_VECTOR:%.c=%_debug.o}
OBJS_OPERS_D	=	${SRCS_OPERS:%.c=%_debug.o}
INCLUDES		=	-Iincludes
RM				=	rm -rf

%.o				:	%.c
					$(CC) ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_debug.o		:	%.c
					$(CC) ${CC_FLAGS_D} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

all				:	$(LIB_NAME) ${NAME}

all_clean		:	$(LIB_NAME) ${NAME} clean

${NAME}			:	$(OBJ_MAIN) $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS)
					$(CC) $(INCLUDES) $^ -L${LIB_PATH} -l$(LIB_NAME_S) -o $(NAME)

debug			:	$(LIB_NAME) ${NAME_D}

${NAME_D}		:	$(OBJ_MAIN_D) $(OBJS_STACK_D) ${OBJS_VECTOR_D} $(OBJS_OPERS_D)
					$(CC) $(INCLUDES) $^ -L${LIB_PATH} -l$(LIB_NAME_S) -o ${NAME_D}

$(LIB_NAME)		:	
					@$(MAKE) -C $(LIB_PATH)

clean			:
					$(RM) ${OBJ_MAIN} $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS) ${OBJ_MAIN_D} ${OBJS_OPERS_D} ${OBJS_STACK_D} ${OBJS_VECTOR_D}
					@${MAKE} clean -C ${LIB_PATH}

fclean			:	clean 
					$(RM) $(NAME) ${NAME_D}
					@$(MAKE) fclean -C $(LIB_PATH)

re				:	fclean all

.PHONY			:	all all_clean debug clean fclean re