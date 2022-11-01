# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:26:05 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/01 18:04:48 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile source files
$(OBJCS_DIR)/$(MAIN_DIR)/%.o : $(PS_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(MAIN_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(CMD_DIR)/%.o : $(PS_DIR)/$(CMD_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(CMD_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(MG_DIR)/%.o : $(PS_DIR)/$(MG_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(MG_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(BONUS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(DS_DIR)/%.o : $(DS_DIR)/$(DEQ_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(DS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(DS_DIR)/%.o : $(DS_DIR)/$(PSS_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(PSS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(DS_DIR)/%.o : $(DS_DIR)/$(TM_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(TM_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@