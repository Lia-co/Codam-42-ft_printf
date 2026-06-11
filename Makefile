# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: shiyuan <shiyuan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2026/06/03 12:53:29 by shiyuan       #+#    #+#                  #
#    Updated: 2026/06/11 15:11:35 by sliang        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#colours
GREEN = \033[1;92m
RED = \033[31m
WHITE = \033[1;60m
RESET = \033[0m

NAME = libftprintf.a
CFLAGS = cc -Wall -Wextra -Werror -g
SRCS = 	ft_printf.c \
		ft_putchr.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putptr.c \

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Object files is removed.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Library and objects files are removed.$(RESET)"

re: fclean all

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "$(GREEN)ft_printf objects files are archived.$(RESET)"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CFLAGS) -c $< -o $@
	@echo "$(WHITE)compiling file $< -->$(RESET) $(GREEN)$@ $(RESET)" 

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREEN)objects directory is created.$(RESET)"
.PHONY: all clean fclean re