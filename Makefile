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
					sort.c median.c find_min_max.c \
					smart_rotate.c sort_median.c \
					sort_quarter.c

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

PRINT_COMPILE = @echo "\033[1;32m⏳ compiling push_swap\033[1;0m"

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

all : lib ${NAME}
	@echo "\033[1;32m✅ push_swap OK\033[1;0m"

${NAME}:	${OBJS} Makefile
	@${CC} ${OBJS} ${LIBFT} -o ${NAME}

$(OBJSDIR)%.o: ${SRCSDIR}%.c ${HEAD}
	@$(MKDIR) $(OBJSDIR)
	@$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)
	@$(PRINT_COMPILE)
	@$(eval PRINT_COMPILE = @:)

clean:
	@${MAKE} clean --no-print-directory -C ${LIBFTDIR}
	@${RM} ${OBJS}
	@echo "\033[1;31m🗑  push_swap cleaned\033[1;0m"

fclean:
	@${RM} ${OBJS}
	@${RM} ${OBJSDIR}
	@${RM} ${NAME}
	@${MAKE} --no-print-directory fclean -C ${LIBFTDIR}
	@echo "\033[1;31m🗑  push_swap cleaned\033[1;0m"

re:
	@${MAKE} --no-print-directory fclean
	@${MAKE} --no-print-directory all

lib:
	@${MAKE}	--no-print-directory -C ${LIBFTDIR}

.PHONY : re all clean fclean printf lib
