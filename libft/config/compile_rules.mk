# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:37:47 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/31 08:37:55 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile rules

$(OBJCS_DIR)/$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(LIBFT_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(BONUS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(PRINTF_DIR)/%.o : $(PRINTF_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(PRINTF_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJCS_DIR)/$(GNL_DIR)/%.o : $(GNL_DIR)/%.c
	@mkdir -p $(OBJCS_DIR)
	@mkdir -p $(OBJCS_DIR)/$(GNL_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@