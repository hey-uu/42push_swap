# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:27:24 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/31 09:11:12 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
DEQ_DIR = dequeue
PSS_DIR = push_swap_set
TM_DIR = triangle_map
OBJCS_DIR = objcs
DIRS = $(OBJCS_DIR) $(OBJCS_DIR)/$(DEQ_DIR) $(OBJCS_DIR)/$(PSS_DIR) $(OBJCS_DIR)/$(TM_DIR) 

# object files
DEQ_OBJCS = $(addprefix $(OBJCS_DIR)/$(DEQ_DIR)/, $(addsuffix .o, $(DEQ_FILES)))
PSS_OBJCS = $(addprefix $(OBJCS_DIR)/$(PSS_DIR)/, $(addsuffix .o, $(PSS_FILES)))
TM_OBJCS = $(addprefix $(OBJCS_DIR)/$(TM_DIR)/, $(addsuffix .o, $(TM_FILES)))
OBJCS = $(DEQ_OBJCS) $(PSS_OBJCS) $(TM_OBJCS)