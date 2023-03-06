# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 11:38:17 by hachahbo          #+#    #+#              #
#    Updated: 2023/03/03 20:04:39 by hachahbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FRACTOL

FRAMEWOKR = -framework OpenGl -framework AppKit -lmlx

SRS =  fractol.c mandelbrot.c  color.c key_handler.c \
		destroy.c ft_strcmp.c burning_ship.c julia.c \
		mouse_events.c

OBJS = $(SRS:.c=.o)



PRINTF = ./ft_printf
AC_PRINTF = $(PRINTF)/libftprintf.a


all : $(NAME)
	@echo  "\t\t\033[0;30m \033[1;30m FRACTOL"
	@echo  "\t\t\033[0;36m \033[1;32m MANDELBROT"
	@echo  "\t\t\033[0;30m \033[1;34m JULIA"
	@echo  "\t\t\033[0;31m \033[1;31m BURNING SHIP"
	
%.o : %.c unchanging.h fractol.h
	cc -Werror -Wall -Werror -c $< -o $@
	
$(NAME) : $(OBJS)
	@make -C $(PRINTF)
	cc -Oz -ffast-math -Werror -Wall -Werror -fsanitize=address $^ $(AC_PRINTF) $(FRAMEWOKR) -o $@

bonus : all

clean :
	@make -C $(PRINTF) $@
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTF) $@
	rm -f $(NAME)

re : fclean all

.phony : all bonus clean fclean re