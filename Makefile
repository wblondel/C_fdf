# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 06:50:34 by wblondel     #+#   ##    ##    #+#        #
#    Updated: 2018/05/08 15:19:02 by wblondel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

## Flags for the C preprocessor
CPPFLAGS = -I$(INC_PATH) -Ilibft/inc -Ilibmlx

## Libraries path
LDFLAGS = -L$(LIBFT_PATH) -L$(LIBMLX_PATH)

## Libraries to link into the executable
LDLIBS = -lft -lmlx -lm

## Name of the executable
NAME = fdf

# Project related variable
SRC_PATH = src
SRC_NAME = calculate.c cam.c clicks.c debug.c draw_map.c draw_ui.c hooks_init.c\
			hooks_keyboard.c hooks_mouse.c hooks_others.c image.c import.c\
			init.c keys.c main.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = inc
HEADER = $(INC_PATH)/clicks.h $(INC_PATH)/fdf.h $(INC_PATH)/keys.h

LIBFT_PATH = libft
LIBMLX_PATH = libmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

# Entry point
all: $(NAME)

# Compiles FdF
$(NAME): $(LIBFT_PATH)/$(LIBFT_PATH).a $(LIBMLX_PATH)/$(LIBMLX_PATH).a $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME) $(LDLIBS) $(FRAMEWORKS)

# Compiles minilibx/minilibx.x
# It's a prerequisite to compile FdF
$(LIBFT_PATH)/$(LIBFT_PATH).a:
	$(MAKE) -C ./$(LIBFT_PATH)

# Compiles libmlx/libmlx.a
# It's a prerequisite to compile FdF
$(LIBMLX_PATH)/$(LIBMLX_PATH).a:
	$(MAKE) -C ./$(LIBMLX_PATH)

# Creates obj/ directory
# It's a prerequisite to compile any OBJ
$(OBJ_PATH):
	mkdir $@

# Adds the dependance to create the directory
# before to compile an object
$(OBJ): | $(OBJ_PATH)

# Compiles all the src into obj
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# /!\ Dirty workaround /!\
# If make on the libft or libmlx directory should rebuild something then PHONY
# the rule libft or libmlx to build it. Otherwise it relinks.
ifeq ($(shell $(MAKE) --question -C ./$(LIBFT_PATH) ; echo $$?), 1)
.PHONY: $(LIBFT_PATH)/$(LIBFT_PATH).a
endif
ifeq ($(shell $(MAKE) --question -C ./$(LIBMLX_PATH) ; echo $$?), 1)
.PHONY: $(LIBMLX_PATH)/$(LIBMLX_PATH).a
endif

.PHONY: clean
clean:
	$(MAKE) -C ./$(LIBFT_PATH) clean
	$(MAKE) -C ./$(LIBMLX_PATH) clean
	$(RM) -r $(OBJ_PATH)

.PHONY: fclean
fclean: clean
	$(MAKE) -C ./$(LIBFT_PATH) fclean
	$(MAKE) -C ./$(LIBMLX_PATH) clean
	$(RM) -r $(NAME) $(NAME).dSYM

.PHONY: re
re: fclean
	$(MAKE) all

.PHONY: norme
norme:
	norminette $(SRC)
	norminette $(INC_PATH)
	norminette $(LIBFT_PATH)/*.h
	norminette $(LIBFT_PATH)/*.c
