
NAME = merge_bp

CC = gcc

FLAGS = -Werror -Wall -Wextra

SRC = ft_dellistbyend.c  ft_deltab.c  ft_merge.c  ft_newchr.c  ft_strcmp.c  ft_strsplit.c  ft_text.c  main.c

all: $(NAME)

$(NAME):	
	@ (cd src/ && $(CC) $(FLAGS) $(SRC) -o ../$(NAME))

fclean:	
	@ /bin/rm -f $(NAME)

re:	fclean all

.PHONY: all fastq_length_filter fclean re

