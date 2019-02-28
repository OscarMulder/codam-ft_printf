# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: omulder <omulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/05 07:59:03 by omulder        #+#    #+#                 #
#    Updated: 2019/02/28 15:53:21 by omulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = printf
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I./ -I./libft/
VPATH = ./libft/
LIBFT = ft_abs.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isspace.c ft_longlen.c \
ft_pow.c ft_putchar_uni.c ft_putchar.c ft_putcharsign.c ft_putlong_base.c \
ft_putnstr.c ft_putnwstr.c ft_putstr.c ft_putulong_base.c ft_putwstr.c \
ft_rputnbr.c ft_strlen.c ft_ulonglen.c ft_wstrlen.c ft_putlong.c ft_isupper.c
SRCS = check_format.c copy_fmt.c find_base.c find_case.c find_conversion.c \
find_length.c find_options.c find_precision.c find_width.c ft_printf.c \
is_char.c is_charp.c is_charsign.c is_conversion.c is_double.c is_flag.c \
is_hex.c is_int.c is_length.c is_long.c is_longint.c is_octal.c is_option.c \
is_short.c is_signed.c is_uchar.c is_uint.c is_ulong.c is_unsigned.c \
is_ushort.c is_voidp.c is_wcharp.c print_char.c print_charp.c print_double.c \
print_padding.c print_prehex.c print_signed.c print_unsigned.c print_var.c \
print_wcharp.c printed_chars.c printed_uchars.c put_backpadding.c \
put_paddingandsign.c put_upaddingandsign.c reset_fmt.c is_ldouble.c \
round_expo.c round_num.c check_special.c is_negzero.c prepare_fmt_num.c \
prepare_fmt_expo.c print_dot.c print_ldouble.c
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