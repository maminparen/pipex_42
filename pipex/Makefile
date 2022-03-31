# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzona <hzona@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 16:12:07 by hzona             #+#    #+#              #
#    Updated: 2021/10/29 22:56:34 by hzona            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = command.c ft_split.c pipex.c command2.c minignl.c strultils.c error.c

SRC_BONUS = command.c ft_split.c pipex_bonus.c command2.c minignl.c strultils.c error.c

SRCS_DIR = src/

OBJS = ${addprefix ${SRCS_DIR}, ${SRC:.c=.o}}

OBJS_BONUS = ${addprefix ${SRCS_DIR}, ${SRC_BONUS:.c=.o}}

HEADER = src/pipex.h

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

.PHONY: all clean fclean re bonus

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC}	${OBJS} -o ${NAME}
			@echo "pipex compiled successfully!"

bonus:		${OBJS_BONUS} ${HEADER}
			@${CC}	${OBJS_BONUS} -o ${NAME}
			@echo "Bonus part: pipex compiled successfully!"

all:		${NAME}

fclean:		
			@${RM} ${OBJS} ${OBJS_BONUS} ${NAME}
			@echo "fclean successfully!"

clean:		
			@${RM} ${OBJS} ${OBJS_BONUS}
			@echo "fclean successfully!"

re: fclean all