#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	push_swap.h

SRCSFILE		=	push_swap.c check_error.c \
					call_sorter.c sort_three.c \
					swap.c push.c rotate.c \
					reverse_rotate.c sort_five.c \
					radix.c

LIBFTSRC	=	libftprintf.a libft.a

#					Directories

HEADERSDIR	=	./inc/

SRCSDIR		=	./src/

LIBFTDIR	=	libft/

OBJSDIR		=	./objs/

#					Full Path

HEAD		=	$(addprefix $(HEADERSDIR),$(HEADERS))

SRCS		=	$(addprefix $(SRCSDIR),$(SRCSFILE))

LIBFT		=	$(addprefix $(LIBFTDIR),$(LIBFTSRC))

OBJS		=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

AR			=	ar rc

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror -g3

CC			=	gcc

RM			=	rm -rf

MKDIR		=	mkdir -p

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

all : ${NAME}

${NAME}:	${OBJS} Makefile
	${MAKE} lib
	${CC} ${OBJS} ${LIBFT} -o ${NAME}

$(OBJSDIR)%.o: ${SRCSDIR}%.c ${HEAD}
	$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

clean:
	${MAKE} clean -C ${LIBFTDIR}
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS}
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}

re:
	${MAKE} fclean
	${MAKE} all

lib:
	${MAKE}	-C ${LIBFTDIR}

.PHONY : re all clean fclean printf lib
