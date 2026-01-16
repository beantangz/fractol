# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleineku <mleineku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 16:48:30 by mleineku          #+#    #+#              #
#    Updated: 2025/06/09 18:23:50 by mleineku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_printf.c \
		printfunctions.c \
		printfunctions2.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
AR = ar rcs
RM = rm -f

# Default rule
all: $(NAME)

# Create .a library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compile .o from .c
%.o: %.c  
	 $(CC) $(CFLAGS) -c $< -o $@

# Clean .o files
clean:
	$(RM) $(OBJ)

# Clean .o files and .a
fclean: clean
	$(RM) $(NAME) $(TEST_BIN)

# Rebuild
re: fclean all
