# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:32:05 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/31 08:34:27 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile source files
$(OBJCS_DIR)/$(DEQ_DIR)/%.o : $(DEQ_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(DEQ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(PSS_DIR)/%.o : $(PSS_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(PSS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(TM_DIR)/%.o : $(TM_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(TM_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@
