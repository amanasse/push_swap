SRCS    = 	ft_split.c\
			push_swap.c\
			ft_pars.c\
			ft_bzero.c\
			utils_lst.c\
			utils_lst2.c\
			utils_init_a.c\
			utils_algo.c\
			utils_algo2.c\
			swap_2_to_5.c\
			operations/operation_swap.c\
			operations/operation_reverse.c\
			operations/operation_rotate.c\
			operations/operation_push.c

OBJS	= ${SRCS:.c=.o}
HEADERS	= "push_swap.h"
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all :		push_swap

.c.o:
	${CC} ${CFLAGS} -c $< -I includes -o ${<:.c=.o}

push_swap :	${OBJS} 
			${CC} -o push_swap ${CFLAGS} ${OBJS} 


clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f push_swap

re:			fclean all 

.PHONY: all clean fclean re