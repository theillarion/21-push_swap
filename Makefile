NAME			=	push_swap
NAME_C			=	my_checker
NAME_D			=	${NAME}_debug
NAME_C_D		=	${NAME_C}_debug
LIB_NAME		=	libft.a
LIB_NAME_D		=	libft_debug.a
LIB_NAME_S		=	ft
LIB_PATH		=	lib/libft/
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FLAGS_D		=	-g
SRCS_MAIN		=	${shell find srcs/push_swap -name "*.c"}
SRCS_SHARED		=	${shell find srcs/shared -name "*.c"}
SRCS_SORT		=	${shell find srcs/sort -name "*.c"}
SRCS_STACK		=	${shell find srcs/stack -name "*.c"}
SRCS_VECTOR		=	${shell find srcs/vector -name "*.c"}
SRCS_OPERS		=	${shell find srcs/operations -name "*.c"}
SRCS_CHECK		=	${shell find srcs/checker -name "*.c"}
SRCS_GNL		=	${shell find srcs/get_next_line -name "*.c"}
OBJS_MAIN		=	${SRCS_MAIN:%.c=%.o}
OBJS_SHARED		=	${SRCS_SHARED:%.c=%.o}
OBJS_SORT		=	${SRCS_SORT:%.c=%.o}
OBJS_STACK		=	${SRCS_STACK:%.c=%.o}
OBJS_VECTOR		=	${SRCS_VECTOR:%.c=%.o}
OBJS_OPERS		=	${SRCS_OPERS:%.c=%.o}
OBJS_CHECK		=	${SRCS_CHECK:%.c=%.o}
OBJS_GNL		=	${SRCS_GNL:%.c=%.o}
OBJS_MAIN_D		=	${SRCS_MAIN:%.c=%_debug.o}
OBJS_SHARED_D	=	${SRCS_SHARED:%.c=%_debug.o}
OBJS_SORT_D		=	${SRCS_SORT:%.c=%_debug.o}
OBJS_STACK_D	=	${SRCS_STACK:%.c=%_debug.o}
OBJS_VECTOR_D	=	${SRCS_VECTOR:%.c=%_debug.o}
OBJS_OPERS_D	=	${SRCS_OPERS:%.c=%_debug.o}
OBJS_CHECK_D	=	${SRCS_CHECK:%.c=%_debug.o}
OBJS_GNL_D		=	${SRCS_GNL:%.c=%_debug.o}
INCLUDES		=	-Iincludes
RM				=	rm -rf

%.o				:	%.c
					$(CC) ${CC_FLAGS} ${INCLUDES} -c $< -o $@

%_debug.o		:	%.c
					$(CC) ${CC_FLAGS_D} ${CC_FLAGS} ${INCLUDES} -c $< -o $@

all				:	${NAME}

all_clean		:	$(LIB_NAME) ${NAME} clean

${NAME}			:	$(LIB_PATH)$(LIB_NAME) $(OBJS_MAIN) $(OBJS_SHARED) $(OBJS_SORT) $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS)
					$(CC) $(INCLUDES) $(OBJS_MAIN) $(OBJS_SHARED) $(OBJS_SORT) $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS) -L${LIB_PATH} -l$(LIB_NAME_S) -o $(NAME)

${NAME_C}		:	$(LIB_PATH)$(LIB_NAME) $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_SHARED) $(OBJS_SORT) $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS)
					$(CC) $(INCLUDES) $(OBJS_CHECK) $(OBJS_GNL) $(OBJS_SHARED) $(OBJS_SORT) $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS) -L${LIB_PATH} -l$(LIB_NAME_S) -o $(NAME_C)

debug			:	${NAME_D}

${NAME_D}		:	$(LIB_PATH)$(LIB_NAME) $(OBJS_MAIN_D) $(OBJS_SHARED_D) $(OBJS_SORT_D) $(OBJS_STACK_D) ${OBJS_VECTOR_D} $(OBJS_OPERS_D)
					$(CC) $(INCLUDES) $(OBJS_MAIN_D) $(OBJS_SHARED_D) $(OBJS_SORT_D) $(OBJS_STACK_D) ${OBJS_VECTOR_D} $(OBJS_OPERS_D) -L${LIB_PATH} -l$(LIB_NAME_S) -o ${NAME_D}

${NAME_C_D}		:	$(LIB_PATH)$(LIB_NAME) $(OBJS_CHECK_D) $(OBJS_GNL_D) $(OBJS_SHARE_D) $(OBJS_SORT_D) $(OBJS_STACK_D) ${OBJS_VECTOR_D} $(OBJS_OPERS_D)
					$(CC) $(INCLUDES) $(OBJS_CHECK_D) $(OBJS_GNL_D) $(OBJS_SHARED_D) $(OBJS_SORT_D) $(OBJS_STACK_D) ${OBJS_VECTOR_D} $(OBJS_OPERS_D) -L${LIB_PATH} -l$(LIB_NAME_S) -o ${NAME_C_D}

$(LIB_PATH)$(LIB_NAME)		:	
					@$(MAKE) -C $(LIB_PATH)

clean			:
					$(RM) ${OBJS_MAIN} $(OBJS_SHARED) $(OBJS_SHARED_D) $(OBJS_SORT) $(OBJS_STACK) ${OBJS_VECTOR} $(OBJS_OPERS) $(OBJS_CHECK) $(OBJS_GNL) ${OBJS_MAIN_D} $(OBJS_SORT_D) ${OBJS_OPERS_D} ${OBJS_STACK_D} ${OBJS_VECTOR_D} $(OBJS_CHECK_D) $(OBJS_GNL_D)
					@${MAKE} clean -C ${LIB_PATH}

fclean			:	clean 
					$(RM) $(NAME) ${NAME_D} ${NAME_C} ${NAME_C_D}
					@$(MAKE) fclean -C $(LIB_PATH)

re				:	fclean all

.PHONY			:	all all_clean debug clean fclean re