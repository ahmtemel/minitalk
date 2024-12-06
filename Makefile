NAME1 = server
NAME2 = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLEAN = rm -rf

all :
		@make -C ./ft_printf
		@$(CC) $(CFLAGS) $(NAME1).c ./ft_printf/libftprintf.a -o $(NAME1)
		@$(CC) $(CFLAGS) $(NAME2).c ./ft_printf/libftprintf.a -o $(NAME2)

bonus :
		@make -C ./ft_printf
		@$(CC) $(CFLAGS) $(NAME1)_bonus.c ./ft_printf/libftprintf.a -o $(NAME1)_bonus
		@$(CC) $(CFLAGS) $(NAME2)_bonus.c ./ft_printf/libftprintf.a -o $(NAME2)_bonus
clean :
		@make clean -C ./ft_printf
		@$(CLEAN) $(NAME1).o $(NAME2).o

fclean : clean
		@make fclean -C ./ft_printf
		@$(CLEAN) $(NAME1) $(NAME2)
		@$(CLEAN) $(NAME1)_bonus $(NAME2)_bonus

re : fclean all

.PHONY : all fclean clean
