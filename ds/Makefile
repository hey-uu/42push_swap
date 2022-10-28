# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:13:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/28 10:53:18 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap_ds.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# libft
LIBFT = libft.a
LIBFT_DIR = ../libft

# files
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
FILES = $(DEQ_FILES) $(PSS_FILES) $(TM_FILES)

# directory of files
DEQ_DIR = ds_dequeue
PSS_DIR = ds_push_swap_set
TM_DIR = ds_triangle_map
OUT_DIR = objcs

# object files
DEQ_OBJCS = $(addprefix $(OUT_DIR)/$(DEQ_DIR)/, $(addsuffix .o, $(DEQ_FILES)))
PSS_OBJCS = $(addprefix $(OUT_DIR)/$(PSS_DIR)/, $(addsuffix .o, $(PSS_FILES)))
TM_OBJCS = $(addprefix $(OUT_DIR)/$(TM_DIR)/, $(addsuffix .o, $(TM_FILES)))
OBJCS = $(DEQ_OBJCS) $(PSS_OBJCS) $(TM_OBJCS)

$(NAME) : build
	make -C $(LIBFT_DIR) all
	cp $(LIBFT_DIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $(OBJCS)

.PHONY : build
build :
	mkdir -p $(OUT_DIR)
	mkdir -p $(OUT_DIR)/$(DEQ_DIR)
	mkdir -p $(OUT_DIR)/$(PSS_DIR)
	mkdir -p $(OUT_DIR)/$(TM_DIR)
	make compile

.PHONY : compile
compile : $(OBJCS)

$(OUT_DIR)/$(DEQ_DIR)/%.o : $(DEQ_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(PSS_DIR)/%.o : $(PSS_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(TM_DIR)/%.o : $(TM_DIR)/%.c
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(RMFLAGS) $(OBJCS)
	@$(RM) $(RMFLAGS) $(OUT_DIR)

.PHONY : fclean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

.PHONY : re
re :
	make fclean
	make all
