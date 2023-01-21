NAME = pipex
CFILES = pipex.c child.c exec.c path.c ft_split.c free.c ft_strdup.c ft_strjoin.c ft_strncmp.c ft_strlen.c ft_putstr.c error.c
OFILES = $(CFILES:%.c=%.o)
HEADER = pipex.h
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OFILES) $(HEADER)
			$(CC) $(OFILES) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
				$(RM) $(OFILES)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
