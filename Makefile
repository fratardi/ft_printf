# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 15:09:05 by tpacaud           #+#    #+#              #
#    Updated: 2019/04/27 16:14:43 by tpacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

LIB = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

C = ./Srcs/Parsing/ft_split_format.c ./Srcs/Parsing/ft_issyntax.c \
	./Srcs/Parsing/ft_format_string1.c ./Srcs/Parsing/ft_format_string2.c \
	./Srcs/Parsing/ft_fill_struct.c \
	./Srcs/Reader/ft_varead.c ./Srcs/Reader/ft_fillelem.c\
	./Srcs/Unicodes/ft_print_uni_char.c ./Srcs/Unicodes/ft_print_uni_str.c\
	./Srcs/Unicodes/ft_uni_char_len.c ./Srcs/Unicodes/ft_uni_str_len.c \
	./Srcs/Display/ft_display.c ./Srcs/Maths/ft_adjustfloat.c \
	./Srcs/Display/ft_convert.c ./Srcs/Display/ft_printdigits.c \
	./Srcs/Display/ft_displaybin.c ./Srcs/Display/ft_dispmod.c\
	./Srcs/Display/size_convert.c \
	./Srcs/Maths/annex_float.c ./Srcs/Maths/annex_ldouble.c\
	./Srcs/Maths/pow_str.c ./Srcs/Maths/ft_addstrings.c \
	./Srcs/ft_printf.c \

C_LIB = ./libft/ft_itoa.o ./libft/ft_freetab.o ./libft/ft_strnlen.o \
		./libft/ft_strndup.o ./libft/ft_swap.o\
		./libft/ft_lstmap.o ./libft/ft_lstiter.o ./libft/ft_lstadd.o \
		./libft/ft_lstdel.o ./libft/ft_lstdelone.o\
		./libft/ft_lstnew.o ./libft/ft_memset.o \
		./libft/ft_putstr_fd.o ./libft/ft_print_table.o\
		./libft/ft_isspace.o ./libft/ft_llitoa.o\
		./libft/ft_strequ.o ./libft/ft_strncat.o\
		./libft/ft_strsplit.o ./libft/ft_atoi.o \
		./libft/ft_memalloc.o ./libft/ft_pow.c ./libft/ft_strjoinfree.c\
		./libft/ft_putchar.o ./libft/ft_strcat.o\
		./libft/ft_striter.o ./libft/ft_strstr.o ./libft/ft_bzero.o\
		./libft/ft_memccpy.o ./libft/ft_putchar_fd.o ./libft/ft_strchr.o \
		./libft/ft_striteri.o ./libft/ft_strncmp.o\
		./libft/ft_strsub.o ./libft/ft_isalnum.o ./libft/ft_memchr.o \
		./libft/ft_putendl.o ./libft/ft_strclr.o ./libft/ft_strjoin.o\
		./libft/ft_strncpy.o ./libft/ft_strtrim.o ./libft/ft_isalpha.o \
		./libft/ft_memcmp.o ./libft/ft_putendl_fd.o \
		./libft/ft_strcmp.o ./libft/ft_strlcat.o ./libft/ft_strnequ.o \
		./libft/ft_tolower.o ./libft/ft_isascii.o \
		./libft/ft_memcpy.o ./libft/ft_putnbr.o ./libft/ft_strcpy.o\
		./libft/ft_strlen.o ./libft/ft_strnew.o \
		./libft/ft_toupper.o ./libft/ft_isdigit.o ./libft/ft_memdel.o \
		./libft/ft_putnbr_fd.o ./libft/ft_strdel.o\
		./libft/ft_strmap.o ./libft/ft_strnstr.o ./libft/ft_isprint.o \
		./libft/ft_memmove.o ./libft/ft_putstr.o\
		./libft/ft_strdup.o ./libft/ft_strmapi.o ./libft/ft_strrchr.o\
		./libft/ft_pow2.c ./libft/ft_ullitoa.c

O = $(C:.c=.o)

O_LIB = $(C_LIB:.c=.o)

all : $(NAME)

$(NAME): $(O) $(O_LIB)
	ar rc $(NAME) $(O) $(O_LIB)
	ranlib $(NAME)

lib :
	make -C ./libft/

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(O)
	make clean -C ./libft/

fclean : clean
	rm -rf $(NAME)
	rm -rf $(LIB)

re : fclean all

.PHONY : all lib clean flean re
