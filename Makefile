# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 16:19:46 by maolivie          #+#    #+#              #
#    Updated: 2019/01/06 22:25:55 by maolivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fillit
CC				= gcc
CFLAGS		   += -Wall -Wextra -Werror
SRCDIR			= srcs/
OBJDIR			= obj/
INCDIR			= includes/

SRC				= main.c \
				  check.c

CFLAGS		   += -I $(INCDIR)
OBJ				= $(SRC:.c=.o)
OUTPUT_OPTION	= -o $(OBJDIR)$@

vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(addprefix $(OBJDIR),$(OBJ))

$(OBJ): %: | $(OBJDIR)

$(OBJDIR):
	mkdir $@

clean:
	rm -Rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
