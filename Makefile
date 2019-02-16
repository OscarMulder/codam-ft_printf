# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/05 07:59:03 by omulder        #+#    #+#                 #
#    Updated: 2019/02/16 15:12:00 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = printf
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/
VPATH = ./libft/
LIBFT = ft_putchar.c ft_rputstr.c ft_rputnbr.c ft_putnbr.c ft_atoi.c \
ft_intlen.c ft_isdigit.c ft_itoa.c ft_isspace.c ft_putnnbr.c ft_rputchar.c \
ft_strlen.c ft_putstr.c ft_putnstr.c ft_putnbr_base.c ft_putlong_base.c \
ft_longlen.c ft_putunbr_base.c ft_putulong_base.c ft_uintlen.c ft_ulonglen.c \
ft_putshort.c ft_putcharsign.c ft_pow.c
SRCS = ft_printf.c debug_printfmt.c check_format.c find_conversion.c \
find_length.c find_options.c find_precision.c find_width.c is_conversion.c \
is_length.c is_flag.c new_fmt.c is_char.c is_charp.c is_double.c is_int.c \
is_longint.c is_voidp.c is_wcharp.c print_var.c find_escape.c print_int.c \
print_char.c print_padding.c print_charp.c is_long.c print_long.c \
print_prehex.c is_unsigned.c print_ulong.c print_uint.c is_short.c \
print_charsign.c is_charsign.c print_short.c find_case.c find_base.c \
is_hex.c printed_chars.c printed_uchars.c put_backpadding.c \
put_upaddingandsign.c put_paddingandsign.c print_double.c is_option.c
OBJECTS = $(SRCS:.c=.o) $(LIBFT:.c=.o)

all: $(OBJECTS) $(NAME)

$(TEST): $(NAME)
	$(CC) -o $(TEST) $(INCLUDES) -L./ -lftprintf main.c
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