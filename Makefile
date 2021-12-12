# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:02:53 by bbrassar          #+#    #+#              #
#    Updated: 2021/12/12 21:51:49 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= hotrace
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -c -I.

SRC					=	main.c \
						hash.c \
						ft_memmove.c \
						ft_memset.c \
						ft_putstr.c \
						ft_strdup.c \
						get_next_line.c \
						btree_create.c \
						btree_destroy.c \
						btree_search.c \
						btree_insert.c \
						btree_balance.c \
						btree_height.c
OBJ					= $(SRC:.c=.o)

$(NAME):			$(OBJ)
					$(CC) $^ -o $@

%.o:				%.c
					$(CC) $(CFLAGS) $< -o $@

all:				$(NAME)

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
