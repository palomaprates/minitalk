CFLAGS = -Wall -Wextra -Werror

SRCS1 = main1.c
SRCS2 = main2.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

NAME1 = program1
NAME2 = program2

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