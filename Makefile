# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsegovia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 10:14:59 by jsegovia          #+#    #+#              #
#    Updated: 2022/02/21 10:15:02 by jsegovia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=n

NAME	=	get_next_line.a

$(NAME):	$(OBJS)
			ar	rcs	$(NAME)	$(OBJS)
			ranlib	$(NAME)

clean:
		$(RM)	$(OBJS)

fclean:	clean
		$(RM)	$(NAME)

print:
		echo$(OBJS)
		echo$(OBJS_A)
		echo$(OBJS_B)

re:		fclean	all

.PHONY:	all	clean	fclean	re
