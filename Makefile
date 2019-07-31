# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 15:09:05 by tpacaud           #+#    #+#              #
#    Updated: 2019/07/31 15:46:36 by tpacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC_PATH = ./includes

INC_NAME = ft_printf.h

C =	./

C_LIB = ./libft/ft_itoa.o \
		./libft/ft_freetab.o \
		./libft/ft_strnlen.o \
		./libft/ft_strndup.o \
		./libft/ft_swap.o \
		./libft/ft_lstmap.o \
		./libft/ft_lstiter.o \
		./libft/ft_lstadd.o \
		./libft/ft_lstdel.o ./libft/ft_lstdelone.o\
		./libft/ft_lstnew.o ./libft/ft_memset.o \
		./libft/ft_putstr_fd.o ./libft/ft_print_table.o\
		./libft/ft_isspace.o ./libft/ft_llitoa.o\
		./libft/ft_strequ.o ./libft/ft_strncat.o\
		./libft/ft_strsplit.o ./libft/ft_atoi.o \
		./libft/ft_memalloc.o ./libft/ft_pow.o ./libft/ft_strjoinfree.o\
		./libft/ft_putchar.o ./libft/ft_strcat.o\
		./libft/ft_striter.o ./libft/ft_strstr.o ./libft/ft_bzero.o\
		./libft/ft_memccpy.o ./libft/ft_putchar_fd.o ./libft/ft_strchr.o \
		./libft/ft_striteri.o ./libft/ft_strncmp.o\
		./libft/ft_strsub.o ./libft/ft_isalnum.o ./libft/ft_memchr.o \
		./libft/ft_putendl.o ./libft/ft_strclr.o ./libft/ft_strjoin.o\
		./libft/ft_strncpy.o ./libft/ft_strtrim.o ./libft/ft_isalpha.o \
		./libft/ft_memcmp.o ./libft/ft_putendl_fd.o ./libft/ft_memaset.o\
		./libft/ft_strcmp.o ./libft/ft_strlcat.o ./libft/ft_strnequ.o \
		./libft/ft_tolower.o ./libft/ft_isascii.o \
		./libft/ft_memcpy.o ./libft/ft_putnbr.o ./libft/ft_strcpy.o\
		./libft/ft_strlen.o ./libft/ft_strnew.o \
		./libft/ft_toupper.o ./libft/ft_isdigit.o ./libft/ft_memdel.o \
		./libft/ft_putnbr_fd.o ./libft/ft_strdel.o\
		./libft/ft_strmap.o ./libft/ft_strnstr.o ./libft/ft_isprint.o \
		./libft/ft_memmove.o ./libft/ft_putstr.o\
		./libft/ft_strdup.o ./libft/ft_strmapi.o ./libft/ft_strrchr.o\
		./libft/ft_pow2.o ./libft/ft_ullitoa.o ./libft/ft_putnstr.o \
		./libft/joinfree.o\

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

O = $(C:.c=.o)

O_LIB = $(C_LIB:.c=.o)

all : temp

temp :
	make -C ./libft
	gcc ft_print2.c libft/libft.a srcs/*/*.c main.c
	make fclean -C ./libft

newline :
	@echo ""

$(NAME): $(O) $(O_LIB) $(INC)
	@echo ""
	@ar rc $(NAME) $(O) $(O_LIB)
	@echo "ar rc of" $(NAME) "is done"
	@ranlib $(NAME)
	@echo "Ranlib of" $(NAME) "is done"

%.o : %.c	
	@$(CC) $(FLAGS) -c $< -o $@
	$(if $(findstring srcs,$@),@echo "Making" $<)
	$(if $(findstring libft/ft_itoa.o,$@), @echo "")
	$(if $(findstring libft/ft_itoa.o,$@), @echo ">>> Making LIBFT ...")

clean :
	@rm -rf $(O)
	@rm -rf $(O_LIB)
	@echo "Cleaning Done (Removed .o)"

fclean : clean
	@rm -rf $(NAME)
	@echo $(NAME) " Removed"
	@rm -rf $(LIB)
	@echo "libft.a Removed"

re : fclean newline all

.PHONY : all lib clean flean re
