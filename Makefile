# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 21:40:54 by adavitas          #+#    #+#              #
#    Updated: 2025/09/30 21:40:55 by adavitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
SRC_DIRS = src libtf
OBJS_DIR = build
SRCS = $(shell find $(SRC_DIRS) -name "*.c")
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

.PHONY: all clean fclean re
all: pipex

pipex: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f pipex

re: fclean all
