NAME = libftprintf.a
LIBFT = libft/libft.a

HEADER = libftprintf.h

FLAGS = -Wall -Wextra -Werror -g

SRCS =		ft_printf.c		\
		ft_itoa_hex.c		\
		ft_itoa_unsigned.c 	\
		ft_stringformat.c	\
		ft_intformat.c		\
		ft_charformat.c		\
		ft_spec_char.c		\
		ft_spec_int.c		\
		ft_flags.c			\
		ft_verifiers.c		\
		ft_strnew.c			\
		ft_printstring.c	\
		ft_fmtptr.c			\

BONUSSRCS = 

OBJS = $(SRCS:.c=.o)

BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(LIBFT):
		make -C libft/

$(NAME): $(LIBFT)
		cp $(LIBFT) $(NAME)
		gcc -c $(FLAGS) -I $(HEADER) $(SRCS)
		ar rc $(NAME) $(OBJS) 
		ranlib $(NAME)
test: $(NAME)
		gcc -o test -fsanitize=address -g $(NAME) maintest.c

clean:
		/bin/rm -f $(OBJS)
		make -C libft/ clean
fclean: clean
		/bin/rm -f $(NAME)
		make -C libft/ fclean
re: fclean all
