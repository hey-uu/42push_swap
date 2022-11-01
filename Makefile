# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 12:39:36 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/01 22:39:59 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(OBJCS)
	make -C $(LIB_DIR) printf_gnl
	$(CC) $(CFLAGS) $(OBJCS) $(LIB) -o $@ -fsanitize=address -g3

.PHONY : bonus
bonus : $(NAME) $(BONUS_NAME)
$(BONUS_NAME) : $(BONUS_OBJCS)
	make -C $(LIB_DIR) printf_gnl
	$(CC) $(CFLAGS) $(BONUS_OBJCS) $(LIB) -o $@ -fsanitize=address -g3

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