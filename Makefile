# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 16:00:20 by hbhuiyan          #+#    #+#              #
#    Updated: 2019/07/12 19:30:02 by hbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	ft_ls

SRC =	./src/*.c

OBJ = 	*.o

INC = 	-I ./includes/ft_ls.h \
		-I ./libft/libft.h \
		-I ./libft/ft_printf/includes/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C ./libft re
	@gcc $(FLAGS) -c -I $(INC) $(SRC)
	@gcc $(FLAGS) $(INC) -L ./libft -lft $(OBJ) -o $(NAME)

clean :
	@rm -fr $(OBJ)
	@find . -type f -name '*.o' -delete
	@find . -type f -name '*.gch' -delete

fclean : clean
	@make -C ./libft/ fclean
	@rm -fr $(NAME)
re :
	@make fclean
	@make all
