# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:55:47 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/01 22:46:24 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands & flags
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# library
LIB_NAME= libft.a
LIB_DIR = libft
LIB = $(LIB_DIR)/$(LIB_NAME)

# file names
PS_FILES = main \
			process_inputs \
			sort_exceptional_cases \
			reduce_commands

CMD_FILES = cmd_multiple_cmds \
			cmd_push \
			cmd_reverse_rotate \
			cmd_rotate \
			cmd_swap \

MG_FILES = merge_sort_compare \
			merge_sort_conquer \
			merge_sort_divide_and_push \
			merge_sort_divide_and_push2 \
			merge_sort_get_idx_highest_priority \
			merge_sort

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

DS_FILES = $(DEQ_FILES) $(PSS_FILES) $(TM_FILES)

BONUS_FILES = checker_utils_bonus \
			checker_main_bonus \
			cmd_push_bonus \
			cmd_reverse_rotate_bonus \
			cmd_rotate_bonus \
			cmd_swap_bonus \
			dequeue_bonus \
			dequeue_utils_bonus \
			process_inputs_bonus \
			push_swap_set_bonus

# directories of files
PS_DIR = mandatory_push_swap

DS_DIR = data_structure
DEQ_DIR = dequeue
PSS_DIR = push_swap_set
TM_DIR = triangle_map

MAIN_DIR = main
CMD_DIR = commands
MG_DIR = merge_sort

BONUS_DIR = bonus_checker

OBJCS_DIR = objcs

# object files
PS_OBJCS = $(addprefix $(OBJCS_DIR)/$(MAIN_DIR)/, $(addsuffix .o, $(PS_FILES)))
CMD_OBJCS = $(addprefix $(OBJCS_DIR)/$(CMD_DIR)/, $(addsuffix .o, $(CMD_FILES)))
MG_OBJCS = $(addprefix $(OBJCS_DIR)/$(MG_DIR)/, $(addsuffix .o, $(MG_FILES)))
DS_OBJCS = $(addprefix $(OBJCS_DIR)/$(DS_DIR)/, $(addsuffix .o, $(DS_FILES)))
OBJCS = $(DS_OBJCS) $(PS_OBJCS) $(CMD_OBJCS) $(MG_OBJCS)

BONUS_OBJCS = $(addprefix $(OBJCS_DIR)/$(BONUS_DIR)/, $(addsuffix .o, $(BONUS_FILES)))
