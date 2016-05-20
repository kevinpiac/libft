#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:06:24 by kpiacent          #+#    #+#              #
#    Updated: 2016/04/27 14:27:40 by kpiacent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCLUDES = -I includes/
SRCS_DIR = srcs/
SRCS = ft_putchar.c ft_putchar_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c \
\
	ft_strlen.c ft_strlcat.c ft_strcmp.c \
	ft_strncmp.c ft_strdup.c ft_strstr.c \
	ft_strnstr.c ft_strcpy.c ft_strncpy.c \
	ft_striter.c ft_striteri.c ft_strchr.c \
	ft_strrchr.c ft_strjoin.c ft_strtrim.c \
	ft_strsub.c ft_strmap.c ft_strmapi.c \
	ft_strsplit.c ft_toupper.c ft_tolower.c \
	ft_atoi.c ft_itoa.c ft_strcat.c \
	ft_strncat.c ft_delsplit.c ft_strindex.c \
	ft_strreplace.c ft_splitcount.c \
\
	ft_islower.c ft_isupper.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_isprint.c \
	ft_isascii.c ft_strequ.c ft_strnequ.c \
	ft_istoskip.c \
\
	ft_memalloc.c ft_memset.c ft_memdel.c \
	ft_memcpy.c ft_memccpy.c ft_strnew.c \
	ft_strdel.c ft_strclr.c ft_bzero.c \
	ft_memchr.c ft_memcmp.c ft_memmove.c \
	ft_realloc.c \
\
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_lstput.c ft_lstputendl.c ft_lstaddback.c \
\
	ft_bitprint.c ft_bitgetfour.c ft_bitsetfour.c \
	ft_bitgetoctal.c ft_bitsetoctal.c \
\
	get_next_line.c \
\
	vector_new.c vector_resize.c vector_add.c \
	vector_addfront.c vector_showall.c vector_insert.c \
	vector_get.c vector_set.c vector_delone.c \
	vector_foreach.c vector_bubblesort.c vector_del.c \
	vector_totab.c \
\
	opm_init.c opm_config_init.c \
	opm_getoption.c opm_getoption_param.c \
	opm_findoption.c opm_findoption_param.c \
	opm_issetoption.c opm_debug.c opm_destroy.c \
	opm_config_destroy.c opm_error.c \
\
	arm_argument_new.c arm_init.c arm_debug.c \
	arm_getparam.c arm_getparam_name.c arm_getparam_type.c \
	arm_findparam.c arm_findallparams.c arm_findalloptions.c \
	arm_isparam.c arm_isoption.c arm_destroy.c \
	arm_tostr.c \
\
	error_print.c

FILES_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
FILES = $(SRCS)
OBJ = $(FILES:.c=.o)
TMP = Makefile~ libft.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) -c $(FILES_PATH) $(INCLUDES) && ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling the libft:		DONE!"
	@rm -rf $(OBJ)
clean :
	@rm -f $(OBJ) $(TMP)
	@echo "Removing all files:		DONE!"
fclean : clean
	@rm -f $(NAME)
	@echo "Removing libft.a:		DONE!"

re : fclean all

testopm :
	@cd tests/opm/ \
	&& gcc -o a.out main.c -L ../../ -lft \
	&& ./a.out $(ARGV)

testclean :
	rm -f a.out

testre : testclean test

.PHONY : clean fclean re
