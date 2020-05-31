NAME = libftprintf.a

HEADER = libftprintf.h

FLAGS = -Wall -Wextra -Werror -g

SRCS =		ft_printf.c		\
		ft_itoa_hex.c		\
		ft_itoa_unsigned.c 	\

BONUSSRCS = 

OBJS = $(SRCS:.c=.o)

BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) -I $(HEADER) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
bonus:
		gcc -c $(FLAGS) -I $(HEADER) $(BONUSSRCS)
		ar rc $(NAME) $(BONUSOBJS)
		ranlib $(NAME)

clean:
		/bin/rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
