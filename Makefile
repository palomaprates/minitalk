CFLAGS = -Wall -Wextra -Werror

SRCS1 = client.c utils/ft_atoi.c
SRCS2 = server.c utils/ft_strlen.c utils/binary_to_char.c utils/binary_to_int.c utils/to_get_len.c utils/to_get_final_str.c utils/ft_itoa.c utils/ft_memset.c


OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

NAME1 = client
NAME2 = server

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1)

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS1) $(OBJS2)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all
