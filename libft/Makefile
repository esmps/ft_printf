NAME = libft.a

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRCS = 		ft_atoi.c 		\
 		ft_bzero.c 		\
 		ft_isalnum.c 		\
 		ft_isalpha.c 		\
 		ft_isascii.c 		\
 		ft_isdigit.c 		\
 		ft_isprint.c 		\
 		ft_calloc.c 		\
 		ft_memccpy.c 		\
 		ft_memchr.c 		\
 		ft_memcmp.c 		\
 		ft_memcpy.c 		\
 		ft_memmove.c 		\
 		ft_memset.c 		\
  		ft_putchar_fd.c 	\
 		ft_putendl_fd.c 	\
  		ft_putnbr_fd.c 		\
  		ft_putstr_fd.c 		\
 		ft_strchr.c 		\
 		ft_strdup.c 		\
 		ft_strjoin.c 		\
 		ft_strlcat.c 		\
		ft_strlcpy.c		\
		ft_strncpy.c		\
 		ft_strlen.c 		\
 		ft_strmapi.c 		\
 		ft_strncmp.c 		\
		ft_strnstr.c 		\
 		ft_strrchr.c 		\
  		ft_substr.c 		\
		ft_tolower.c 		\
 		ft_toupper.c 		\
		ft_itoa.c			\
		ft_split.c			\
		ft_strtrim.c		\
		ft_lstnew.c			\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstlast.c		\
		ft_lstmap.c			\
		ft_lstsize.c		\
		ft_abs.c			\
		ft_islower.c		\
		ft_isupper.c		\
		ft_isspace.c		\
		ft_pow.c			\
		ft_putchar.c		\
		ft_putendl.c		\
		ft_putnbr.c			\
		ft_putstr.c			\
		ft_strcat.c			\
		ft_strcpy.c			\
		ft_strstr.c			\
		ft_strnew.c			\
		ft_itoa_hex.c		\
		ft_itoa_unsigned.c	\
					 

OBJS = $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) -g -I $(HEADER) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
