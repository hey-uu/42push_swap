# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:55:47 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/31 09:16:06 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands & flags
CFLAGS = -Wall -Wextra -Werror 
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# library
LIB_NAME= pushswap_ds.a
LIB_DIR = data_structure
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
			merge_sort_get_idx_highest_priority \
			merge_sort
BONUS_FILES = checker_main_bonus

# directories of files
PS_DIR = mandatory_push_swap
MAIN_DIR = main
CMD_DIR = commands
MG_DIR = merge_sort
BONUS_DIR = bonus_checker
OBJCS_DIR = objcs

# object files
PS_OBJCS = $(addprefix $(OBJCS_DIR)/$(MAIN_DIR)/, $(addsuffix .o ,$(PS_FILES)))
CMD_OBJCS = $(addprefix $(OBJCS_DIR)/$(CMD_DIR)/, $(addsuffix .o ,$(CMD_FILES)))
MG_OBJCS = $(addprefix $(OBJCS_DIR)/$(MG_DIR)/, $(addsuffix .o ,$(MG_FILES)))
OBJCS = $(PS_OBJCS) $(CMD_OBJCS) $(MG_OBJCS)

BONUS_OBJCS = $(addprefix $(OBJCS_DIR)/$(BONUS_DIR)/, $(addsuffix .o, $(BONUS_FILES)))
CHECKER_OBJCS = $(BONUS_OBJCS) $(CMD_OBJCS) $(MG_OBJCS) objcs/main/process_inputs.o
