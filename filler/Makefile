#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvysotsk <vvysotsk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:38:51 by vvysotsk          #+#    #+#              #
#    Updated: 2018/10/15 13:38:52 by vvysotsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY : all clean fclean re

NAME = vvysotsk.filler

CFLAGS = -Wall -Werror -Wextra -I includes/

FILES =	src/checker.c src/filler.c src/generate.c src/help_parser.c src/pad.c \
		src/parser.c src/place_fig.c src/sheet.c src/visual.c\
		libft/printf/bonus.c libft/printf/form_out.c libft/printf/ft_printf.c \
		libft/printf/handler.c libft/printf/help_handler.c libft/printf/identify.c \
		libft/printf/num.c libft/printf/num_help.c libft/printf/parser.c libft/printf/simple_func.c \
		libft/printf/str.c libft/printf/uni.c libft/printf/wstr.c \
		libft/ft_atoi.c libft/ft_bzero.c libft/ft_count_char.c  libft/ft_count_str.c libft/ft_find_char.c \
		libft/ft_find_nword.c libft/ft_imaxtoa.c libft/ft_int_len.c libft/ft_isalnum.c libft/ft_isalpha.c \
		libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_itoa_base.c \
		libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c \
		libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c \
		libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c \
		libft/ft_putchar_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_realloc.c libft/ft_recalloc.c \
		libft/ft_save_str.c libft/ft_save_to_str.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c \
		libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c \
		libft/ft_striter.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c \
		libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strndup.c \
		libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c \
		libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c \
		libft/ft_uimaxtoa_base.c libft/get_next_line.c libft/my_pad.c libft/my_write.c libft/stnchr.c \

OBJ = $(subst .c,.o, $(FILES))

all: $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -c $? -o $@

$(NAME): $(OBJ)
	@gcc $(OBJ) -lncurses -o $(NAME)
	@echo "\033[32mvvysotsk.filler Created\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32mObject Files Removed\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mvvysotsk.filler Removed\033[0m"

re: fclean all