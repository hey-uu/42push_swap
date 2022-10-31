# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:13:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/31 08:34:09 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap_ds.a

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(OBJCS)
	make -C $(LIBFT_DIR) printf_gnl
	cp $(LIBFT_DIR)/$(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $(OBJCS)

include config/compile_rules.mk

.PHONY : clean fclean re
clean :
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(RMFLAGS) $(OBJCS_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all
