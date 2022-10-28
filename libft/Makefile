# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/28 10:52:56 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -f

FILES = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_strchr \
		ft_strdup \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_tolower \
		ft_toupper \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		./ft_printf/ft_printf \
		./ft_printf/printf_utils \
		./ft_printf/put_characters \
		./ft_printf/put_integers_utils \
		./ft_printf/put_integers \
		ft_push_swap_atol
		
BONUS_FILES = ft_lstadd_back \
		 	ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstnew \
			ft_lstsize \
			ft_lstlast \
			ft_lstmap

SRCS = $(addsuffix .c, $(FILES))
OBJCS = $(addsuffix .o, $(FILES))
BONUS_SRCS = $(addsuffix .c, $(BONUS_FILES))
BONUS_OBJCS = $(addsuffix .o, $(BONUS_FILES))

ifdef WITH_BONUS
	TOTAL_OBJCS = $(OBJCS) $(BONUS_OBJCS)
else
	TOTAL_OBJCS = $(OBJCS)
endif

$(NAME) : $(TOTAL_OBJCS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

bonus :
	make WITH_BONUS=1 all

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJCS) $(BONUS_OBJCS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus
