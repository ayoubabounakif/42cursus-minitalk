FLAGS = -Wall -Wextra -Werror

BONUS = bonus

SERVER = server
EXEC_SERVER = server

CLIENT = client
EXEC_CLIENT = client

SERVER_SRC = server.c
SERVER_SRC_BONUS = server_bonus.c
CLIENT_SRC = client.c
CLIENT_SRC_BONUS = client_bonus.c

UTILS = utils/ft_atoi.c \
utils/ft_isdigit.c \
utils/ft_putchar_fd.c \
utils/ft_putstr_fd.c \
utils/ft_putnbr_fd.c \
utils/ft_putendl_fd.c

all: $(SERVER) $(CLIENT)

$(SERVER):
	@echo "\033[0;32mCompilation in progress!"
	gcc $(FLAGS) $(SERVER_SRC) $(UTILS) -o $(EXEC_SERVER)
	@echo "\033[0;34mCompilation done."
	rm -rf $(EXEC_SERVER).dSYM

$(CLIENT):
	@echo "\033[0;32mCompilation in progress!"
	gcc $(FLAGS) $(CLIENT_SRC) $(UTILS) -o $(EXEC_CLIENT)
	@echo "\033[0;34mCompilation done."
	rm -rf $(EXEC_CLIENT).dSYM

$(BONUS):
	@echo "\033[0;32mCompilation in progress! BONUS"
	gcc $(FLAGS) $(SERVER_SRC_BONUS) $(UTILS) -o $(EXEC_SERVER)
	gcc $(FLAGS) $(CLIENT_SRC_BONUS) $(UTILS) -o $(EXEC_CLIENT)
	@echo "\033[0;34mCompilation done."

clean:
	rm -f *.o
	@echo "\033[0;3mCleaned"

fclean: clean
	rm -f *.a
	rm -f $(EXEC_SERVER)
	rm -f $(EXEC_CLIENT)
	@echo "\033[0;31mEverything cleaned"

re: fclean all