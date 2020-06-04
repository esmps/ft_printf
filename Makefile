NAME = libftprintf.a
LIBFT = libft/libft.a

HEADER = libftprintf.h

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS =		ft_printf.c		\
		ft_itoa_hex.c		\
		ft_itoa_unsigned.c 	\
		ft_fmtstr.c		\
		ft_fmtint.c		\
		ft_intspec.c		\
		ft_charspec.c		\
		ft_flags.c		\
		ft_verifiers.c		\

BONUSSRCS = 

OBJS = $(SRCS:.c=.o)

BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(LIBFT):
		make -C libft/

$(NAME): $(LIBFT)
		gcc -c $(FLAGS) -I $(HEADER) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
test: $(NAME)
		gcc -g -fsanitize=address -o test $(LIBFT) $(NAME) maintest.c
bonus:
		gcc -c $(FLAGS) -I $(HEADER) $(BONUSSRCS)
		ar rc $(NAME) $(BONUSOBJS)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJS) $(BONUSOBJS)
		make -C libft/ clean
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
