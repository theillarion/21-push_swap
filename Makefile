NAME			=	push_swap
LIB_NAME		=	libft.a
LIB_SNAME		=	ft
LIB_PATH		=	lib/libft/
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FDEBUG		=	-g
SRC_MAIN		=	srcs/main.c
SRCS_STACK		=	${shell find srcs/stack -name "*.c"}
SRCS_OPERATIONS	=	${shell find srcs/operations -name "*.c"}
OBJ_MAIN		=	${SRC_MAIN:.c=.o}
OBJS_STACK		=	${SRCS_STACK:.c=.o}
OBJS_OPERATIONS	=	${SRCS_OPERATIONS:.c=.o}
INCLUDES		=	-Iincludes
RM				=	rm -rf

.c.o					:	
							$(CC) $(INCLUDES) $(CC_FLAGS) -c $< -o $(<:.c=.o)

all						:	$(LIB_NAME) ${NAME}

${NAME}					:	$(OBJ_MAIN) $(OBJS_STACK) $(OBJS_OPERATIONS)
							$(CC) $(CC_FLAGS) $(INCLUDES) $(OBJ_MAIN) $(OBJS_STACK) $(OBJS_OPERATIONS) -L${LIB_PATH} -l$(LIB_SNAME) -o $(NAME)

debug					:	$(LIB_NAME) ${NAME}_debug

${NAME}_debug			:	$(OBJ_MAIN) $(OBJS_STACK) $(OBJS_OPERATIONS)
							$(CC) $(CC_FLAGS) $(CC_FDEBUG) $(OBJ_MAIN) $(OBJS_STACK) $(OBJS_OPERATIONS) -L${LIB_PATH} -l$(LIB_SNAME) -o $(NAME)_debug

$(LIB_NAME)				:	
							@$(MAKE) -C $(LIB_PATH)

clean					:
							$(RM) $(OBJS_STACK) $(OBJS_OPERATIONS)

fclean					:	clean 
							$(RM) $(NAME) $(NAME)_debug
							@$(MAKE) fclean -C $(LIB_PATH)

re						:	fclean all

.PHONY					:	all clean fclean re