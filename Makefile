# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 12:39:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/10/31 08:56:39 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(OBJCS)
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(OBJCS) $(LIB) -o $@ -fsanitize=address -g3

.PHONY : bonus
bonus : $(NAME) $(BONUS_NAME)
$(BONUS_NAME) : $(CHECKER_OBJCS)
	$(CC) $(CFLAGS) $(CHECKER_OBJCS) $(LIB) -o $@ -fsanitize=address -g3

include config/compile_rules.mk

.PHONY : clean fclean re
clean :
	make -C $(LIB_DIR) fclean
	$(RM) $(RMFLAGS) $(OBJCS_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all