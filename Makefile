NAME			=	push_swap
#NAME_CLIENT		=	client
CC 				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra
CC_FDEBUG		=	-g
SRCS_STACK		=	${shell find srcs/stack -name "*.c"}
#SRCS_CLIENT		=	${shell find srcs/client -name "*.c"}
#SRCS_SHARED		=	$(shell find srcs/shared -name "*.c")
OBJS_STACK		=	${SRCS_STACK:.c=.o}
#OBJS_CLIENT		=	${SRCS_CLIENT:.c=.o}
#OBJS_SHARED		=	${SRCS_SHARED:.c=.o}
INCLUDES		=	-I includes
RM				=	rm -rf

.c.o					:	
							$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all						:	${NAME} ${NAME_CLIENT}

${NAME}					:	$(OBJS_STACK)
							$(CC) $(CC_FLAGS) $(OBJS_STACK) $(OBJS_SHARED) -o $(NAME)

#debug					:	${NAME}_debug ${NAME_CLIENT}_debug

#${NAME}_debug	:	$(OBJS_STACK) $(OBJS_SHARED)
#							$(CC) $(CC_FLAGS) $(CC_FDEBUG) $(OBJS_STACK) $(OBJS_SHARED) -o $(NAME)_debug

clean					:
							$(RM) $(OBJS_STACK)
# $(OBJS_CLIENT) $(OBJS_SHARED)

fclean					:	clean 
							$(RM) $(NAME)
# $(NAME_CLIENT) $(NAME)_debug $(NAME_CLIENT)_debug

re						:	fclean all

.PHONY					:	all clean fclean re