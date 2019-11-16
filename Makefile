NAME = lols

all : $(NAME)

$(NAME):
		make -C libft/ 
		gcc -g gnl/*.c *.c libft/libft.a -I /usr/local/include -L /usr/local/lib/ -lmlx -framework openGL -framework AppKit ./libft/libft.a
		#gcc gnl/*.c *.c ./libft/libft.a

clean:
	make clean -C libft
	rm -rf *.o

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
