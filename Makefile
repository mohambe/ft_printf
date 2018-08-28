# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 16:30:35 by msambo            #+#    #+#              #
#    Updated: 2018/08/16 15:00:13 by msambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = $(addprefix sources/,new.c ft_width.c ft_print_str.c ft_print_char.c ft_print_nbr.c\
	   ft_print_hex.c ft_print_oct.c ft_multi_datatype.c ft_itoa_b.c ft_digit.c ps.c the_number1.c\
	   ft_flags.c ft_datatype.c ft_tolower.c ft_print_p.c unsigned.c the_hash.c the_hex_hash.c)
LIBS = $(addprefix function/,ft_strcpy.c ft_atoi.c ft_strlen.c ft_strchr.c ft_strcat.c ft_strdel.c\
	   ft_strsub.c ft_bzero.c ft_strnew.c ft_itoa.c ft_isdigit.c ft_strjoin.c ft_memdel.c ft_strdup.c) 
OBJECTS = new.o ft_width.o ft_print_str.o ft_print_char.o ft_print_nbr.o\
	   ft_print_hex.o ft_itoa_b.o ft_multi_datatype.o ft_digit.o ft_memdel.o\
	   ft_flags.o ft_datatype.o ft_strcpy.o ft_itoa.o ft_atoi.o ft_strdel.o\
	   ft_strlen.o ft_tolower.o ft_strchr.o ft_strsub.o ft_bzero.o ft_strdup.o\
	   ft_strnew.o ft_print_oct.o ft_isdigit.o ft_print_p.o unsigned.o\
	   the_hash.o the_hex_hash.o ps.o ft_strjoin.o ft_strcat.o the_number1.o 

#lft : make -C libft/all
.PHONY : fclean
.PHONY: clean
#libft

all: $(NAME)


$(NAME): $(OBJECTS)
	ar -ru $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS) $(LIBS)
	cc -c $(SRCS) $(LIBS) -Wall -Wextra -Werror

clean:
	/bin/rm -f $(OBJECTS)
	/bin/rm -f ft_printf.h.gch

fclean: clean
	/bin/rm -f $(NAME)
re: fclean all