#CC=gcc
NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
SRC = 	ft_abs.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_factorial.c\
		ft_gcd.c\
		ft_intlen.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isblank.c\
		ft_iscntrl.c\
		ft_isdigit.c\
		ft_isgraph.c\
		ft_islower.c\
		ft_isprint.c\
		ft_ispunct.c\
		ft_isspace.c\
		ft_isupper.c\
		ft_itoa.c\
		ft_labs.c\
		ft_lcm.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putchar.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_sqrt.c\
		ft_str_startswith.c\
		ft_str_endswith.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcountwords.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strmerge.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strndup.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnjoin.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtolower.c\
		ft_strtoupper.c\
		ft_strtrim.c\
		ft_swap_c.c\
		ft_swap_i.c\
		ft_swap.c\
		ft_tolower.c\
		ft_toupper.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	/bin/rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
