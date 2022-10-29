# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:13:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/29 10:55:53 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap_ds.a

# commands & flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# libft
LIBFT = libft.a
LIBFT_DIR = ../libft

# file names
DEQ_FILES = dequeue_duplicate \
			dequeue_generate \
			dequeue_get_value \
			dequeue_push_or_pop \
			dequeue_show

PSS_FILES = push_swap_set_generate \
			push_swap_set_show
TM_FILES = triangle_map_generate \
			triangle_map_get_idx \
			triangle_map_show
# directory of files
DEQ_DIR = ds_dequeue
PSS_DIR = ds_push_swap_set
TM_DIR = ds_triangle_map
OBJCS_DIR = objcs
DIRS = $(OBJCS_DIR) $(OBJCS_DIR)/$(DEQ_DIR) $(OBJCS_DIR)/$(PSS_DIR) $(OBJCS_DIR)/$(TM_DIR) 
# object files
DEQ_OBJCS = $(addprefix $(OBJCS_DIR)/$(DEQ_DIR)/, $(addsuffix .o, $(DEQ_FILES)))
PSS_OBJCS = $(addprefix $(OBJCS_DIR)/$(PSS_DIR)/, $(addsuffix .o, $(PSS_FILES)))
TM_OBJCS = $(addprefix $(OBJCS_DIR)/$(TM_DIR)/, $(addsuffix .o, $(TM_FILES)))
OBJCS = $(DEQ_OBJCS) $(PSS_OBJCS) $(TM_OBJCS)

.PHONY : all
all : $(NAME)

$(NAME) : $(DIRS) $(OBJCS)
	make -C $(LIBFT_DIR) printf_gnl
	cp $(LIBFT_DIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $(OBJCS)

# make directorys
$(OBJCS_DIR) :
	@mkdir -p $(OBJCS_DIR)
$(OBJCS_DIR)/$(DEQ_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(DEQ_DIR)
$(OBJCS_DIR)/$(PSS_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(PSS_DIR)
$(OBJCS_DIR)/$(TM_DIR) :
	@mkdir -p $(OBJCS_DIR)/$(TM_DIR)

# compile source files
$(OBJCS_DIR)/$(DEQ_DIR)/%.o : $(DEQ_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(PSS_DIR)/%.o : $(PSS_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(TM_DIR)/%.o : $(TM_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY : clean fclean re
clean :
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(RMFLAGS) $(OBJCS_DIR)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re :
	make fclean
	make all
