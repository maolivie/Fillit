# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maolivie <maolivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 16:19:46 by maolivie          #+#    #+#              #
#    Updated: 2019/01/25 05:38:27 by maolivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
SRCDIR	= srcs
OBJDIR	= obj

HEAD	= $(SRCDIR)/fillit.h

SRC		= main.c \
		  parsing.c \
		  output.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

GREEN	= \033[1;32m
PURPLE	= \033[1;35m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(GREEN)Compiling\t$(YELLOW)$@ $(WHITE)with $^"
	@$(CC) -o $@ $^
	@echo "$@  \t[$(GREEN)✓$(WHITE)]"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)'"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
