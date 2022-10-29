# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/29 16:55:58 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# file names
LIBFT_FILE = ft_atoi \
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
		ft_push_swap_atol
		
PRINTF_FILE = ft_printf \
			printf_utils \
			put_characters \
			put_integers_utils \
			put_integers

GNL_FILE = get_next_line_utils \
			get_next_line

BONUS_FILE = ft_lstadd_back \
		 	ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstnew \
			ft_lstsize \
			ft_lstlast \
			ft_lstmap

# directory files
OBJCS_DIR = objcs
LIBFT_DIR = ft_libft_mandatory
BONUS_DIR = ft_libft_bonus
PRINTF_DIR = ft_printf
GNL_DIR = ft_get_next_line
DIRS = $(OBJCS_DIR) $(OBJCS_DIR)/$(LIBFT_DIR) $(OBJCS_DIR)/$(BONUS_DIR) \
		$(OBJCS_DIR)/$(PRINTF_DIR) $(OBJCS_DIR)/$(GNL_DIR)
# # source files
# LIBFT_SRCS = $(addsuffix .c, $(LIBFT_FILE))
# BONUS_SRCS = $(addsuffix .c, $(BONUS_FILE))
# PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_FILE)))
# GNL_SRCS = $(addprefix $(GNL_DIR), $(addsuffix .c $(GNL_FILE)))
# object files
LIBFT_OBJCS = $(addprefix $(OBJCS_DIR)/$(LIBFT_DIR)/, $(addsuffix .o, $(LIBFT_FILE)))
BONUS_OBJCS = $(addprefix $(OBJCS_DIR)/$(BONUS_DIR)/, $(addsuffix .o, $(BONUS_FILE)))
PRINTF_OBJCS = $(addprefix $(OBJCS_DIR)/$(PRINTF_DIR)/, $(addsuffix .o, $(PRINTF_FILE)))
GNL_OBJCS = $(addprefix $(OBJCS_DIR)/$(GNL_DIR)/, $(addsuffix .o, $(GNL_FILE)))
OBJCS = $(LIBFT_OBJCS) $(B_OBJCS) $(P_OBJCS) $(G_OBJCS)

# variables
ifdef WITH_BONUS
	B_OBJCS = $(BONUS_OBJCS)
endif

ifdef WITH_PRINTF
	P_OBJCS = $(PRINTF_OBJCS)
endif

ifdef WITH_GNL
	G_OBJCS = $(GNL_OBJCS)
endif

CHECK = 0


.PHONY : all
all : $(NAME)

$(NAME) : $(DIRS) $(OBJCS)
	$(AR) $(ARFLAGS) $@ $(OBJCS)

# make directorys
$(OBJCS_DIR) :
	@mkdir -p $(OBJCS_DIR)
$(OBJCS_DIR)/$(LIBFT_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(LIBFT_DIR)
$(OBJCS_DIR)/$(BONUS_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(BONUS_DIR)
$(OBJCS_DIR)/$(PRINTF_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(PRINTF_DIR)
$(OBJCS_DIR)/$(GNL_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(GNL_DIR)

# compile
$(OBJCS_DIR)/$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY : bonus printf gnl printf_gnl
bonus :
	# libft with linked list utils
	@make WITH_BONUS=1 all
printf :
	# libft with ft_printf
	@make WITH_PRINTF=1 all
gnl :
	# libft with get_next_line
	@make WITH_GNL=1 all
printf_gnl :
	# libft with printf and get_next_line
	@make WITH_PRINTF=1 WITH_GNL=1 all

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJCS_DIR)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : 
	make fclean
	make all

