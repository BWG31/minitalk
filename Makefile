# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 15:58:30 by bgolding          #+#    #+#              #
#    Updated: 2024/01/22 13:42:28 by bgolding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME		=	client

S_NAME		=	server

INC_D		=	inc/
SRC_D		=	src/
CL_D		=	client/
SV_D		=	server/
OBJ_D		=	obj/

CL_BASE		=	client client_utils
SV_BASE		=	server server_utils

CL_SRC		=	$(addprefix $(SRC_D)$(CL_D), $(addsuffix .c, $(CL_BASE)))
SV_SRC		=	$(addprefix $(SRC_D)$(SV_D), $(addsuffix .c, $(SV_BASE)))

CL_OBJ		=	$(addprefix $(OBJ_D), $(addsuffix .o, $(CL_BASE)))
SV_OBJ		=	$(addprefix $(OBJ_D), $(addsuffix .o, $(SV_BASE)))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f


DEF_COLOR	=	\033[0;39m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m

all:			$(C_NAME) $(S_NAME)

$(C_NAME):		$(CL_OBJ)
				$(CC) $(CFLAGS) $^ -o $@

$(S_NAME):		$(SV_OBJ)
				$(CC) $(CFLAGS) $^ -o $@

$(OBJ_D)%.o:	$(SRC_D)$(CL_D)%.c
				@mkdir -p $(OBJ_D)
				$(CC) $(CFLAGS) -I$(INC_D) -c $< -o $@

$(OBJ_D)%.o:	$(SRC_D)$(SV_D)%.c
				@mkdir -p $(OBJ_D)
				$(CC) $(CFLAGS) -I$(INC_D) -c $< -o $@

bonus:			all

clean:
				$(RM) -r $(OBJ_D)
			
fclean:			clean
				$(RM) $(C_NAME) $(S_NAME)

re:				fclean	all

.PHONY:			all clean fclean