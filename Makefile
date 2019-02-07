# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/05 07:59:03 by omulder        #+#    #+#                 #
#    Updated: 2019/02/07 12:14:48 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = printf
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/
VPATH = ./libft/
LIBFT = ft_putchar.c ft_rputstr.c ft_rputnbr.c ft_putnbr.c ft_atoi.c \
ft_intlen.c ft_isdigit.c ft_itoa.c ft_isspace.c
SRCS = ft_printf.c debug_printfmt.c check_format.c find_conversion.c \
find_length.c find_options.c find_precision.c find_width.c is_conversion.c \
is_length.c is_flag.c new_fmt.c
OBJECTS = $(SRCS:.c=.o) $(LIBFT:.c=.o)

all: $(OBJECTS) $(NAME) clean $(TEST)

$(TEST): $(NAME)
	$(CC) -o $(TEST) $(FLAGS) $(INCLUDES) -L./ -lftprintf main.c
	make clean

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SRCS) $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

re: fclean all

reprintf: fclean
	rm -f $(printf)
	make $(TEST)