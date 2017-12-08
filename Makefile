# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 06:50:34 by wblondel     #+#   ##    ##    #+#        #
#    Updated: 2017/12/08 07:06:23 by wblondel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# Compiler configuration
#CC = gcc
CFLAGS = -Wall -Wextra -Werror

## Flags for the C preprocessor
CPPFLAGS = -I$(INC_PATH)

## Libraries path
LDFLAGS = -L$(LIBFT_PATH) -L$(LIBMLX_PATH)

## Libraries to link into the executable
LDLIBS = -lft -lmlx

## Name of the executable
NAME = mlx

# Project related variable
SRC_PATH = src
SRC_NAME = main.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = inc

LIBFT_PATH = libft
LIBMLX_PATH = libmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

# Tracks malloc() and free()
ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif

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
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# /!\ Dirty workaround /!\
# If make on the libft or libmlx directory should rebuild something then PHONY
# the rule libft or libmlx to build it. Otherwise it relinks.
ifeq ($(shell $(MAKE) --question -C ./$(LIBFT_PATH) ; echo $$?), 1)
.PHONY: $(LIBFT_PATH)/$(LIBFT_PATH).a
endif
ifeq ($(shell $(MAKE) --question -C ./$(LIBMLX_PATH) ; echo $$?), 1)
.PHONY: $(LIMLX_PATH)/$(LIBMLX_PATH).a
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
