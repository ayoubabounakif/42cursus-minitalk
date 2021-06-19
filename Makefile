FLAGS = 

LIBNAME = libft.a

SERVER = server
EXEC_SERVER = server

CLIENT = client
EXEC_CLIENT = client

SERVER_SRC = server.c

CLIENT_SRC = client.c

all: $(LIBNAME) $(SERVER) $(CLIENT)

$(LIBNAME):
	@echo "\033[0;35mCompiling libft."
	make -C libft/
	cp libft/$(LIBNAME) ./

$(SERVER): $(LIBNAME)
	@echo "\033[0;32mCompilation in progress!"
	gcc -g3 $(FLAGS) $(SERVER_SRC) libft.a -D BUFFER_SIZE=1024 -o $(EXEC_SERVER)
	@echo "\033[0;34mCompilation done."
	rm -rf $(EXEC_SERVER).dSYM

$(CLIENT): $(LIBNAME)
	@echo "\033[0;32mCompilation in progress!"
	gcc -g3 $(FLAGS) $(CLIENT_SRC) libft.a -D BUFFER_SIZE=1024 -o $(EXEC_CLIENT)
	@echo "\033[0;34mCompilation done."
	rm -rf $(EXEC_CLIENT).dSYM

clean:
	make clean -C libft/
	rm -f *.o
	@echo "\033[0;3mCleaned"

fclean: clean
	make fclean -C libft/
	rm -f *.a
	rm -f $(EXEC_SERVER)
	rm -f $(EXEC_CLIENT)
	@echo "\033[0;31mEverything cleaned"

re: fclean all