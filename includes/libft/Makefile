CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_calloc.c   ft_isascii.c  ft_itoa.c    ft_memcpy.c  ft_striteri.c  ft_strlcpy.c  ft_strncmp.c  ft_strtrim.c  ft_toupper.c \
ft_atoi.c  ft_isalnum.c  ft_isdigit.c  ft_memchr.c  ft_strchr.c  ft_strjoin.c   ft_strlen.c   ft_strnstr.c  ft_substr.c \
ft_bzero.c  ft_isalpha.c  ft_isprint.c  ft_memcmp.c  ft_memset.c   ft_strdup.c  ft_strlcat.c   ft_strmapi.c  ft_strrchr.c  ft_tolower.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_memmove.c ft_split.c

NAME=libft.a
OFILES = $(FILES:.c=.o)
BONUSES=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OFILES_BONUSES = $(BONUSES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES) 
	ar rcs $(NAME) $(OFILES) 

all: $(NAME) clean
clean:
	rm -f $(OFILES) $(OFILES_BONUSES) 
fclean:  
	rm -f $(NAME)
re: fclean all
bonus: $(OFILES) $(OFILES_BONUSES)
	ar rcs $(NAME) $(OFILES) $(OFILES_BONUSES) 

.PHONY : all so clean fclean re bonus
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(FILES) $(BONUSES)
	gcc -nostartfiles -shared -o libft.so $(OFILES) $(OFILES_BONUSES)











