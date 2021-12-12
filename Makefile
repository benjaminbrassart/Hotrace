# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 21:02:53 by bbrassar          #+#    #+#              #
#    Updated: 2021/12/12 15:50:38 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= hotrace
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -c -MMD -MP -I. -g

DIR_SRC				= src
DIR_OBJ				= obj
SRC					=	main.c \
						hash.c \
						ft/ft_memmove.c \
						ft/ft_memset.c \
						ft/ft_putstr.c \
						ft/ft_strdup.c \
						ft/get_next_line.c \
						btree/btree_create.c \
						btree/btree_destroy.c \
						btree/btree_search.c \
						btree/btree_insert.c \
						btree/btree_balance.c \
						btree/btree_height.c
OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP					= $(OBJ:.o=.d)

$(NAME):			$(OBJ)
					$(CC) $^ -o $@

-include $(DEP)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) $< -o $@

all:				$(NAME)

clean:
					rm -rf $(DIR_OBJ)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
