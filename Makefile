##############################################################################################################################################
##############################################################################################################################################

NAME = libftprintf.a

########################################################### LIBFT FILES ######################################################################
##############################################################################################################################################
LIBFT_SRC = libft/

LIBFT_FILES =	ft_substr.c	ft_strjoin.c	ft_strtrim.c	ft_memset.c	ft_bzero.c	ft_strlen.c	ft_strchr.c	ft_isascii.c	ft_memcpy.c	ft_memccpy.c	ft_memmove.c	ft_memchr.c ft_memcmp.c	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isprint.c	ft_toupper.c	ft_tolower.c	ft_strrchr.c	ft_strncmp.c	ft_strlcpy.c	ft_strlcat.c	ft_strnstr.c	ft_atoi.c	ft_calloc.c	ft_strdup.c	ft_split.c	ft_itoa.c	ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

LIBFT_OBJ = $(patsubst %.c, $(LIBFT_SRC)%.o, $(LIBFT_FILES))
#############################################################################################################################################
#############################################################################################################################################



########################################################### HEADERS FILES ####################################################################
##############################################################################################################################################
HEADER_LIST = $(LIBFT_SRC)libft.h	ft_printf.h
##############################################################################################################################################
##############################################################################################################################################



########################################################### PRINTF_FILES #####################################################################
##############################################################################################################################################
PRINTF_LIST = add_chars.c	do_decimal.c	do_prec.c	do_u.c	do_strings.c	do_pxX.c	ft_printf.c	get_flags.c	get_opt.c	get_precision.c	get_width.c	process_opt.c	process_precision.c	process_spec.c	process_width.c	spec.c

PRINTF_LIST_B = 

PRINTF_OBJ = $(patsubst %.c, %.o, $(PRINTF_LIST))

PRINTF_OBJ_B = $(patsubst %.c, %.o, $(PRINTF_LIST_B))
##############################################################################################################################################
##############################################################################################################################################



FLAGS = -Wall -Werror -Wextra

#main : 
#	gcc $(FLAGS)  $(PRINTF_LIST) $(LIBFT_OBJ) main.c -o printf

all : $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME) : $(PRINTF_OBJ) $(LIBFT_OBJ) $(HEADER_LIST)
	ar rcs $(NAME) $?

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(PRINTF_OBJ) $(LIBFT_OBJ)

bonus : 
	make OBJ="$(PRINTF_LIST_B)" all

re : fclean all

.PHONY : all clean fclean re bonus
