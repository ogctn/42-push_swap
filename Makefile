# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 15:28:28 by ogcetin           #+#    #+#              #
#    Updated: 2023/09/18 17:33:07 by ogcetin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./mandatory/atom.c \
		./mandatory/finish_operations.c \
		./mandatory/init_node.c \
		./mandatory/init_stack.c \
		./mandatory/node_utils.c \
		./mandatory/parse1.c \
		./mandatory/parse2.c \
		./mandatory/push_swap.c \
		./mandatory/push.c \
		./mandatory/reversed_rotates.c \
		./mandatory/rotates.c \
		./mandatory/sort_less.c \
		./mandatory/swaps.c \
		

SRCBS =	./bonus_checker/checker.c \
		./bonus_checker/parse1.c \
		./bonus_checker/parse2.c \
		./bonus_checker/push.c \
		./bonus_checker/reversed_rotates.c \
		./bonus_checker/rotates.c \
		./bonus_checker/swaps.c \
		./bonus_checker/init_stack.c \
		./bonus_checker/node_utils.c \
		./bonus_checker/apply_rule.c \
		./bonus_checker/atom.c \
		

NAME = push_swap
NAME_CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = ./Libft/libft.a
GET_NEXT_LINE = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
RM = rm -rf

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	@gcc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "------------------------"
	@echo "|       push_swap      |"
	@echo "|     Mandatory OK!    |"
	@echo "------------------------"


bonus : $(SRCBS) $(GET_NEXT_LINE) $(LIBFT)
	@gcc $(CFLAGS) $(SRCBS) $(GET_NEXT_LINE) $(LIBFT) -o $(NAME_CHECKER)
	@echo "------------------------"
	@echo "|      push_swap       |"
	@echo "|      Bonus OK!       |"
	@echo "------------------------"

$(LIBFT) :
	@make -C ./Libft

clean:
	@make fclean -C ./Libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_CHECKER)
	@make fclean -C ./Libft

re: fclean all

.PHONY: all bonus clean fclean re .c.o