# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 12:39:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/29 16:46:52 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

# commands & flags
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# library
LIB_NAME= pushswap_ds.a
LIB_DIR = ds
LIB = $(LIB_DIR)/$(LIB_NAME)
# file names
PS_FILES = push_swap_main \
			push_swap_process_inputs \
			push_swap_sort_exceptional_cases \
			push_swap_reduce_commands

CMD_FILES = cmd_multiple_cmds \
			cmd_push \
			cmd_reverse_rotate \
			cmd_rotate \
			cmd_swap \

MG_FILES = merge_sort_compare \
			merge_sort_conquer \
			merge_sort_divide_and_push \
			merge_sort_get_idx_highest_priority \
			merge_sort
BONUS_FILES = checker_main_bonus
# directories of files
PS_DIR = ps
CMD_DIR = push_swap_commands
MG_DIR = push_swap_merge_sort
OBJCS_DIR = objcs
DIRS = $(OBJCS_DIR) $(OBJCS_DIR)/$(CMD_DIR) $(OBJCS_DIR)/$(MG_DIR)

BONUS_DIR = bonus_checker
CHECKER_DIRS = $(DIRS) $(OBJCS_DIR)/$(BONUS_DIR)
# object files
PS_OBJCS = $(addprefix $(OBJCS_DIR)/, $(addsuffix .o ,$(PS_FILES)))
CMD_OBJCS = $(addprefix $(OBJCS_DIR)/$(CMD_DIR)/, $(addsuffix .o ,$(CMD_FILES)))
MG_OBJCS = $(addprefix $(OBJCS_DIR)/$(MG_DIR)/, $(addsuffix .o ,$(MG_FILES)))
OBJCS = $(PS_OBJCS) $(CMD_OBJCS) $(MG_OBJCS)

BONUS_OBJCS = $(addprefix $(OBJCS_DIR)/$(BONUS_DIR)/, $(addsuffix .o, $(BONUS_FILES)))
CHECKER_OBJCS = $(BONUS_OBJCS) $(CMD_OBJCS) $(MG_OBJCS) objcs/push_swap_process_inputs.o

.PHONY : all
all : $(NAME)
$(NAME) : $(DIRS) $(OBJCS)
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(OBJCS) $(LIB) -o $@ 

.PHONY : bonus
bonus : $(NAME) $(BONUS_NAME)
$(BONUS_NAME) : $(CHECKER_DIRS) $(BONUS_OBJCS)
	$(CC) $(CFLAGS) $(CHECKER_OBJCS) $(LIB) -o $@ -fsanitize=address -g3

# make directorys
$(OBJCS_DIR) :
	mkdir -p $(OBJCS_DIR)
$(OBJCS_DIR)/$(CMD_DIR) :
	mkdir -p $(OBJCS_DIR)/$(CMD_DIR)
$(OBJCS_DIR)/$(MG_DIR) :
	mkdir -p $(OBJCS_DIR)/$(MG_DIR)
$(OBJCS_DIR)/$(BONUS_DIR) :
	mkdir -p $(OBJCS_DIR)/$(BONUS_DIR)

# compile source files
$(OBJCS_DIR)/%.o : $(PS_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(CMD_DIR)/%.o : $(PS_DIR)/$(CMD_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(MG_DIR)/%.o : $(PS_DIR)/$(MG_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJCS_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY : clean fclean re
clean :
	make -C $(LIB_DIR) fclean
	@$(RM) $(RMFLAGS) $(OBJCS_DIR)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)
re :
	make fclean
	make all